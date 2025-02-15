class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int sum = 0;
        int cnt = 0;        
        set<int> st;
        for(int i=0;i<banned.size();i++)
        {
            if(banned[i] <= n) 
                st.insert(banned[i]);
        }

        for(int i=1;i<=n;i++)
        {
            if(st.contains(i))
                  continue;
            sum += i;
            if(sum <= maxSum)
            {
                cnt++;
            }
        }
        return cnt;
    }
};