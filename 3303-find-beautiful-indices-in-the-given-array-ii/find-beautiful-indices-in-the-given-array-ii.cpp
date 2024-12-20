class Solution {
public:
    vector<int> getKmp(string s, string a)
    {
        vector<int> lps(s.size(), 0);
        for(int i=1;i<s.size();i++)
        {
            int prevIndx = lps[i-1];
            while(prevIndx > 0 && s[i] != s[prevIndx])
            {
                prevIndx = lps[prevIndx-1];
            }
            lps[i] = prevIndx + (s[i] == s[prevIndx] ? 1 : 0);
        }
        
            return lps;
        
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       string s1 = a + '#' + s;
       string s2 = b + '#' + s;
        
       vector<int>lps1 = getKmp(s1,a);
       vector<int> lps2 = getKmp(s2,b);
        vector<int> matchA;
        vector<int> matchB;

        for(int i=0;i<lps1.size();i++)
        {
            if(lps1[i] == a.size())
            {
                matchA.push_back(i - 2*a.size());
            }
        }

        for(int i=0;i<lps2.size();i++)
        {
            if(lps2[i] == b.size())
            {
                matchB.push_back(i - 2*b.size());
            }
        }
    
       
        vector<int>result;
        for(int i=0;i<matchA.size();i++)
        {
            auto it = lower_bound(matchB.begin(), matchB.end(), matchA[i]-k);
            if ((it != matchB.end()) && (abs(*it - matchA[i]) <= k)) result.push_back(matchA[i]);
        }
        return result;    
    }
};