#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution {
public:
    int getLargestOutlier(std::vector<int>& nums) {
        int totalSum = 0;
        std::unordered_map<int, int> mp;
        int ans = INT_MIN;

        for (int num : nums) {
            totalSum += num;
            mp[num]++;
        }

        for (int num : nums) {
            int remainingSum = totalSum - num;
            if (mp.find(remainingSum / 2) != mp.end() && (remainingSum % 2 == 0) && ((remainingSum / 2 != num) || (mp[num] > 1))) {
                ans = std::max(num, ans);
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
