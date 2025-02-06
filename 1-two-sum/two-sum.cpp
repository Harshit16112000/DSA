class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        mp[nums[0]] =  0;
   
        
        for(int i=1;i<nums.size();i++)
        {
            int rem = target - nums[i];
            if(mp.count(rem) == 1){
                return {mp[target - nums[i]],i};
    
            }
        mp[nums[i]] = i;
        
        }
        return {-1,-1};
    }
};