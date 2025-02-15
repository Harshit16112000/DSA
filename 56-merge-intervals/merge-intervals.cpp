class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
    int n = arr.size(); // size of the array
    //sort the given intervals:
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        // end <= ans.back()[1]. Is also valid.
        if (!ans.empty() && end <= ans.back().back()) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
    }
};