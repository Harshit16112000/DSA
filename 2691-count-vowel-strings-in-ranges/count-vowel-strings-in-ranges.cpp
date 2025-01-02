class Solution {
public:
    bool isVowel(string str, int idx) {
        if (str[idx] == 'a' || str[idx] == 'e' || str[idx] == 'i' ||
            str[idx] == 'o' || str[idx] == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> pSum(words.size(), 0);

        if (isVowel(words[0], 0) && isVowel(words[0], words[0].size() - 1))
            pSum[0] = 1;

        for (int i = 1; i < words.size(); i++) {
            int sz = words[i].size();
            if (isVowel(words[i], 0) && isVowel(words[i], sz-1)) {
                pSum[i] = 1 + pSum[i - 1];
            }
            else
               pSum[i] = pSum[i-1];
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(pSum[queries[i][1]] - (queries[i][0] == 0 ? 0 : pSum[queries[i][0] -1]));
        }

        for(int i=0;i<pSum.size();i++)
        {
            cout << pSum[i] << " ";
        }
        return ans;
    }
};