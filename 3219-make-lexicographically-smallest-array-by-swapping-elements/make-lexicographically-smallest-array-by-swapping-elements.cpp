class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Store the indices of each number
        multimap<int, int> mp; // Use multimap to handle duplicates
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp.insert({nums[i], i});
        }

        vector<int> ans(n, -1);
        vector<int> sortedarr;    // Current group of sorted numbers
        vector<int> IndexArr;     // Indices corresponding to the current group

        auto it = mp.begin(); // Iterate through sorted numbers
        while (it != mp.end()) {
            int current_val = it->first; // Current value in sorted order
            int current_idx = it->second; // Original index of this value
            
            // Missed to check with sortedarr.empty()
            if (sortedarr.empty() || current_val - sortedarr.back() <= limit) {
                // Add to current group
                sortedarr.push_back(current_val);
                IndexArr.push_back(current_idx);
            } else {
                // Process current group and start a new one
                sort(IndexArr.begin(), IndexArr.end());
                for (int i = 0; i < sortedarr.size(); i++) {
                    ans[IndexArr[i]] = sortedarr[i];
                }
                sortedarr.clear();
                IndexArr.clear();
                // Start a new group

                // I have missed to add this part
                sortedarr.push_back(current_val);
                IndexArr.push_back(current_idx);
            }
            it++;
        }

        // Handle the last group
        // ALso, missed this part
        if (!sortedarr.empty()) {
            sort(IndexArr.begin(), IndexArr.end());
            for (int i = 0; i < sortedarr.size(); i++) {
                ans[IndexArr[i]] = sortedarr[i];
            }
        }

        return ans;
    }
};
