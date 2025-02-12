class Solution {
public:
    int Count(long curr, long next, int n)
    {
        int countNum = 0;

        while(curr <= n)
        {
            countNum += (next-curr);
            next = next*10;
            curr = curr * 10;
            next = min(next, long(n+1));
        }
        return countNum;

    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k-= 1;

        while(k >0)
        {
            int cntNum = Count(curr, curr+1,n);
            if(cntNum <= k)
            {
                curr++;
                k-= cntNum;
            }
            else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};