class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            int cnt = 0;
            int vari = nums[i];
            while(nums[i] > 9)
            {
                cnt += nums[i]%10;
                nums[i] = nums[i]/10;
            }
            cnt += nums[i];
            //cout << cnt << " ";
            mpp[cnt].insert(vari);
        }
        //cout << endl;

        int maxi = -1;
        for(auto &[key,value] : mpp)
        {
            if(value.size() > 1)
            {
               auto it = value.rbegin();
                int largest = *it;
                int secondLargest = *(++it);
                maxi = max(maxi, largest + secondLargest);
            }
        }

        return maxi;
    
    }
};