class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mp1[128] = {0};
        char mp2[128] = {0};

        for(int i=0;i<t.size();i++){
            if(mp1[s[i]] != mp2[t[i]])   return false;
            mp2[t[i]] = i+1;
            mp1[s[i]] = i+1;
            
        }

        
        return true;
    }
};