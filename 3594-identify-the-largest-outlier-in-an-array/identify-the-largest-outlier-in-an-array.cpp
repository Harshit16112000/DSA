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

        // Thought to sort the alforithm, and then check it in last two element, which is bigger,
        // It didn't work out.
        // Next Intuition is of 
        // we need to take all sum and remove the current item ( outlier item) and then the sum should be double of one of the items in the considered items.
        // One corner case is => when the double of the total sum is equal to the outlier item
        //then in this case we need to check its freq => if greater then equal to 2 that means even we remove one of them as outlier we have at least one more which can be the sum of remaining.

        for (int num : nums) {
            totalSum += num;
            mp[num]++;
        }

        for (int num : nums) {
            int remainingSum = totalSum - num;
            // The same element should not be present in Map. Think of that.
             if (mp.find(remainingSum / 2) != mp.end() 
            && (remainingSum % 2 == 0) && ((remainingSum / 2 != num) || (mp[num] > 1))) {
                ans = std::max(num, ans);
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
