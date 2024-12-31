class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (s1 == s2) return true;

        if (n1 != n2) return false;
        
        string key = s1+" "+s2;
        
		if(mp.find(key)!=mp.end())
            return mp[key];

        for (int i = 1; i < n1; i++) {
            // Split s1 into left1 and right1
            string left1 = s1.substr(0, i);
            string right1 = s1.substr(i);

            // Split s2 into left2 and right2
            string left2 = s2.substr(0, i);
            string right2 = s2.substr(i);

            // Case 1: Check without swap 
            if (isScramble(left1, left2) && isScramble(right1, right2)) {
                mp[key] = true;
                return true;
            }

            // Check With Swap
            if (isScramble(left1, s2.substr(n1-i)) && isScramble(right1, s2.substr(0, n1-i))) {
                mp[key] = true;
                return true;
            }
        }

        return mp[key] = false;
        
    }
};
