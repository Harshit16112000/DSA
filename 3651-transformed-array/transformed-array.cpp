class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int k = nums.size();
        vector<int> result(k,0);
        
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i] == 0)
                {
                    result[i] = nums[i];
                }
                else if(nums[i] > 0)
                {   
                    //swap(result[(i+nums[i])%k],  result[i]);
                    result[i] = nums[(i + nums[i]) % k];
                }
                else
                {   
                    int newIndex = (i+nums[i]+k)%k;
                    if(newIndex < 0)
                        newIndex += k;
                    result[i] = nums[newIndex];
                }
            }

        return result;
    }
};