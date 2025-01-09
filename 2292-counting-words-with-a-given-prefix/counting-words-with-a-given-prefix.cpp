class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(int i=0;i<words.size();i++)
        {
            if(words[i].starts_with(pref)) cnt++;
        }
        return cnt;
    }
};