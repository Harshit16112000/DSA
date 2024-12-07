class Solution {
public:
    bool check(const vector<int>& piles, int k, int h) 
    { 
        int cnt = 0; 
        for(int i = 0; i < piles.size(); i++)
         {
             cnt += (piles[i] + k - 1) / k;
              // This is a more efficient way to 
              //calculate the ceiling 
              if(cnt > h) return false; 
              } 
        return true; 
        }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        int sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            r = max(r,piles[i]);
        } 
        
        int ans= r;

        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(check(piles,mid,h))
            {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};