class Solution {
public:
    // Since, each number is reached one time, only, so, TC- 0(N)
    // Space Complexity. The depth till which we are going in 0(number of digit in N = log10N) only. Not more than that.
    void solve(int i, int n, vector<int> & result)
    {
        if(i > n)  return ;

        result.push_back(i);
        for(int j=0;j<10;j++)
        {
            int num = i*10 + j;
            if(num <= n)
               solve(num,n,result);
        }
        return;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i=1;i<=9;i++)
        {
            solve(i,n,result);
        }
        return result;
    }
};