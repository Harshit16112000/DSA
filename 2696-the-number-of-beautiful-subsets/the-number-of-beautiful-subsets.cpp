#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, unordered_map<int, int>& mp, int idx, int k) {
        if (idx >= nums.size()) return 1;  
        int take = 0;
        if (mp[nums[idx] + k] ==0 && mp[nums[idx] -k] == 0) {
            mp[nums[idx]]++;
            take = solve(nums, mp, idx + 1, k);  
            mp[nums[idx]]--;
        }

        int not_taken = solve(nums, mp, idx + 1, k);
        return not_taken + take;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int ans = solve(nums, mp, 0, k);
        return ans - 1;  
    }
};
