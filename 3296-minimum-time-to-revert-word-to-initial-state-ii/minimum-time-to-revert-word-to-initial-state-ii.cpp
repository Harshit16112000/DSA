class Solution {
public:
     vector<int> getKmp(string &s)
     {
        vector<int> lps(s.size(), 0);
        
        for(int i=1;i<s.size();i++)
        {
            int minIndx = lps[i-1];
            while(minIndx > 0 && s[minIndx] != s[i])
               minIndx = lps[minIndx-1];
            lps[i] = minIndx + (s[i] == s[minIndx] ? 1 : 0); 
        }
        return lps;
     }

    int minimumTimeToInitialState(string word, int k) {
       vector<int> lps = getKmp(word);
       
        int n = word.size();
       int lpsMax = lps[word.size() -1];
       while(lpsMax > 0 && (n - lpsMax )%k != 0)
       {
            lpsMax = lps[lpsMax-1]; 
             
       }
    return (n- lpsMax)%k == 0 ? (n- lpsMax)/k : (n+k-1)/k;
    }
};