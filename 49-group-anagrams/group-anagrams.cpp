class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mpp;
        vector<vector<string>> ans;

        for(int i=0;i<strs.size();i++)
        {
            string original = strs[i];
            string sorted = original;
            sort(sorted.begin(), sorted.end());
            mpp[sorted].push_back(original); 
        }

        for(const auto& [key,value] : mpp)
        {
            vector<string> tempAns;
            for(auto it: value)
            {
                tempAns.push_back(it);
            }
            ans.push_back(tempAns);
        }

        return ans;
    }
};