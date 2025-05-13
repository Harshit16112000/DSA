class Solution {
public:
    const int MOD = 1000000007;
    int lengthAfterTransformations(string s, int t) {
        int freq[26] = {0};
        
        for(char c: s)
        {
            freq[c - 'a']++;
        }

        while(t--)
        {
            int nfreq[26] = {0};
            for(int i=1;i<26;i++)
            {
                nfreq[i] = freq[i-1];
            }

            nfreq[0] = (nfreq[0]  + freq[25])%MOD;
            nfreq[1] = (nfreq[1]  + freq[25])%MOD;

            for(int i=0;i<26;i++)
            {
                freq[i] = nfreq[i];
            }
        }

        int cnt = 0;
        for(int i=0;i<26;i++)
            cnt = (cnt + freq[i])%MOD;
        return cnt;
    }
};