class Solution {
public:
    bool isPossibile(int n,int mid, vector<int>& quantities)
    {
        int cnt = 0;
        for(int i=0;i<quantities.size();i++)
        {
            int ele = quantities[i]/ mid;
            cnt += ele;
            if(quantities[i]%mid)  cnt++;
            if(cnt > n) return false;  
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int r = 0;
        for(int i=0;i<quantities.size();i++)
        {
            r = max(r, quantities[i]);
        }

        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(isPossibile(n,mid,quantities))
            {
                r = mid -1 ;
            }
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};