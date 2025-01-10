class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<int,int> mpp;
        for(int i=0;i<words2.size();i++)
        {
            unordered_map<int,int> mp;
            for(int j=0;j<words2[i].size();j++) {
                mp[words2[i][j] - 'a']++;
            }

            for(int j=0;j<26;j++)
            {
                mpp[j] = max(mpp[j], mp[j]);
            }
        }

        vector<string> ans;
        for(int i=0;i<words1.size();i++)
        {
            unordered_map<int,int> mp2;
            for(int j=0;j<words1[i].size();j++)
            {
                mp2[words1[i][j]-'a']++;
            }
            bool flag = true;
            for(int j=0;j<26;j++)
            {
                if(mp2[j] < mpp[j]) {  flag = false; break;}
            }
            if(flag == true)  ans.push_back(words1[i]);
        }
        return ans;
    }
};