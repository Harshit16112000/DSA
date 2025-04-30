class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int numcnt = 0;
            while (num > 0) {
                num = num / 10;
                numcnt++;
            }
            if (numcnt % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};