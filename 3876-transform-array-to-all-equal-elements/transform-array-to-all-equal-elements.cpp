class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Try to make all 1s
        vector<int> arr1 = nums;
        int cnt = 0;
        bool flag = false;
        
        for (int i = 0; i < n - 1; i++) {
            if (arr1[i] == 1) continue;

            if (arr1[i]  != 1) {
                cnt++;
                arr1[i] = -arr1[i];
                arr1[i + 1] = -arr1[i + 1];
            } else {
                flag = true;
            }
        }

        if (arr1[n - 1] == 1 && !flag && cnt <= k) {
            return true;
        }

        // Try to make all -1s
        vector<int> arr2 = nums;
        cnt = 0;
        flag = false;

        for (int i = 0; i < n - 1; i++) {
            if (arr2[i] == -1) continue;

            if (arr2[i] != -1) {
                cnt++;
                arr2[i] = -arr2[i];
                arr2[i + 1] = -arr2[i + 1];
            } else {
                flag = true;
            }
        }

        if (arr2[n - 1] == -1 && !flag && cnt <= k) {
            return true;
        }

        return false;
    }
};
