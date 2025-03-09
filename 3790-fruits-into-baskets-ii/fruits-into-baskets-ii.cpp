class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        map<int,int> mpp;
        int k = 0;
        for(auto it: baskets) {
            mpp[k] = 0;
            k++;
        }

        for(int i=0;i<fruits.size();i++)
        {
            for(int j=0;j<baskets.size();j++)
            {
                if(baskets[j] >= fruits[i] && mpp[j] == 0)
                {
                    mpp[j] = 1;
                    break;
                }
            }
        }

        int ans = 0;
        for(auto &[key,value] : mpp)
        {
            if(value == 0) ans++; 
        }

        return ans;   
    }
};