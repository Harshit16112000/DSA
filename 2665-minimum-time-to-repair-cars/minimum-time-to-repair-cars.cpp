class Solution {
public:
    bool isPossible(vector<int>& ranks, long long cars, long long time)
    {
        long long cnt = 0;
        for(auto it: ranks)
        {
            
            cnt +=  sqrt(time/it);
            if(cnt >= cars)  return true;
        }
        return cnt >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long  r = 1e14;
        long long l = 0;

        while(l <= r)
        {
            long long  mid = l + (r-l)/2;

            if(isPossible(ranks,cars,mid)) {
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return l;
    }
};