class Solution {
public:
    int maximumLength(string s) {
        map<string,int> mp;

        for(int i=0;i<s.size();i++)
        {
            string currents;
            for(int j=i;j<s.size();j++)
            {
                if(currents.empty() || currents.back() == s[j])
                {
                    currents.push_back(s[j]);
                    mp[currents]++;
                }
                else {
                    break;
                }
            }
        }
            int maxLength = 0;
            for(auto &[substring,count] : mp)
            {
                if(count >= 3)
                maxLength = max(maxLength, (int)substring.length());
            }
            return maxLength == 0 ? -1: maxLength;
        
    }
};