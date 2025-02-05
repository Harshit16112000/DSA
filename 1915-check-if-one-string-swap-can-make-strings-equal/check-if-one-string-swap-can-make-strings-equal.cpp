class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int> mp;
        int cnt = 0;
        int index = 0;
        
        for(int i=0;i<n;i++)
        {
            if(s1[i] != s2[i]) {
                cnt++;
                mp[s1[i]]++;
                mp[s2[i]]--;
            }
        }

        if (cnt > 2) return false;

        for(auto &[key,value] : mp)
        {
            if(value < 0 || value%2 == 1) {
                return false;
            }
        }
        return true;
    }
};