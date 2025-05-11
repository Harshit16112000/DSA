class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int l=*min_element(begin(bloomDay),end(bloomDay));
        int r=  *max_element(begin(bloomDay),end(bloomDay));

        if(m  > n/k)  return -1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int c=0;
            int tt=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)c++;
                else c=0;
                if(c==k){
                    tt++;
                    c=0;
                }
            }
            if(tt>=m){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};