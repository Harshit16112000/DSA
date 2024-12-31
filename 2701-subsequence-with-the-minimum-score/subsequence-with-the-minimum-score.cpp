class Solution {
public:
    int minimumScore(string s, string t) {
        int ss = s.size();
        int ts = t.size();

        int j = ts -1;
        int k = ts -1;
        vector<int> dp(ts, -1);

        for(int i=ss-1; i>=0;i--)
        {
            if(j >= 0 && s[i] == t[k])
            {
                dp[k] = i;
                j--;
                k--;
            }
        }

        int ans = k+ 1;
        if(ans == 0)  return 0;

        for(int i=0,j=0;i<ss;i++)
        {
            if(j < ts && t[j] == s[i]) {
                while(k < ts && dp[k] <= i) k++;

                ans = min(ans, k-j-1);
                j++;
            }
        }


        return ans;
    }
};