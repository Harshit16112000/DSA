class Solution {
public:
    bool checkSimilarity(string word, string original)
    {
        for(int i=0;i<word.size();i++)
        {
            if(word[i] != original[i])  return false;
        }
        return true;
    }
    
    int minimumTimeToInitialState(string word, int k) {
     int n = word.size();
     string original = word;
     int cnt = 0;
     bool flag = true;
     for(int i=0;i<n;i++)
     {
        word.erase(0,k);
        cnt++;
        
        if(checkSimilarity(word, original)) return cnt;
     }   
     return cnt;
    }
};