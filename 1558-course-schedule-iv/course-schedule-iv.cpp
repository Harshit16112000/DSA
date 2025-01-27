class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Transitive closure matrix
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));

        // Build adjacency list
        vector<vector<int>> adjMat(numCourses);
        for (const auto& prereq : prerequisites) {
            adjMat[prereq[0]].push_back(prereq[1]);
        }

        // Topological sort with BFS
        vector<int> inDegree(numCourses, 0);
        for (const auto& prereq : prerequisites) {
            inDegree[prereq[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            for (int nextCourse : adjMat[course]) {
                // Update transitive closure matrix
                isPrerequisite[course][nextCourse] = true;
                for (int i = 0; i < numCourses; i++) {
                    if (isPrerequisite[i][course]) {
                        isPrerequisite[i][nextCourse] = true;
                    }
                }

                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Process queries
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }

        return result;
    }
};
