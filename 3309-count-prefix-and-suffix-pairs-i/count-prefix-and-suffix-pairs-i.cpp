class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            string str = words[i];
            for(int j=i+1;j<n;j++)
            {
                if(words[j].starts_with(str) && words[j].ends_with(str))  cnt++;
            }
        }
        return cnt;
    }
};