class Solution {
public:
    bool checkSpeed(vector<int>& piles, int mid, int h)
    {
        int cnt = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%mid == 0)  cnt+= piles[i]/mid;
            else  cnt += piles[i]/mid + 1;

            if(cnt > h )  return true;
         }
         return false;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i=0;i<piles.size();i++)
        {
            high = max(high, piles[i]);
        }
        int mid = 0;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(checkSpeed(piles,mid,h))
            {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};