class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zero(n, 0);
        vector<int> one(n, 0);


        if(s[0] == '0') 
            zero[0] = 1;

        for(int i=1;i<n;i++)
        {
            if(s[i] == '0') 
              zero[i] = zero[i-1] + 1;
            else
             zero[i] = zero[i-1]; 
        }

        if(s[n-1] == '1')
            one[n-1] = 1;

        for(int i=n-2;i>=0;i--)
        {
            if(s[i] == '1')
               one[i] = 1 + one[i+1];
            else
                one[i] = one[i+1];
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {  
            ans = max(ans, zero[i] + one[i + 1]);
        }
        return ans; 
    }
};