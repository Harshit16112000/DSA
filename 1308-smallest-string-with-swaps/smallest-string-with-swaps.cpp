class Solution {
public:
    void DFS(vector<int> &visited, int currentNode, string &inputString, string &componentChars, 
             vector<int> &componentIndices, vector<vector<int>> &adjList) {
        visited[currentNode] = 1;                // Mark the current node as visited
        componentChars += inputString[currentNode];  // Add the character to the component
        componentIndices.push_back(currentNode);    // Add the index to the component
        
        for (auto neighbor : adjList[currentNode]) { // Traverse all neighbors
            if (!visited[neighbor]) {
                DFS(visited, neighbor, inputString, componentChars, componentIndices, adjList);
            }
        }
    }

    string smallestStringWithSwaps(string inputString, vector<vector<int>>& swapPairs) {
        int n = inputString.size();
        vector<vector<int>> adjList(n);   
        
        for (int i = 0; i < swapPairs.size(); i++) {
            adjList[swapPairs[i][0]].push_back(swapPairs[i][1]);
            adjList[swapPairs[i][1]].push_back(swapPairs[i][0]);
        }

        vector<int> visited(n, 0);       
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {           
                string componentChars = "";       // To store characters in the current 
                vector<int> componentIndices;     // To store indices in the current component
                
                
                DFS(visited, i, inputString, componentChars, componentIndices, adjList);
                
                sort(componentIndices.begin(), componentIndices.end());
                sort(componentChars.begin(), componentChars.end());

                for (int j = 0; j < componentIndices.size(); j++) {
                    inputString[componentIndices[j]] = componentChars[j];
                }
            }
        }

        return inputString;
    }
};
