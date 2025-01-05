class Solution {
public:
    long long calculateScore(string s) {
        map<char, stack<int>> mp;
        long long int result = 0;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            int dis =  c - 'a';
            int mirror = (char) ('z' - dis);

            if(mp.find(mirror) != mp.end() && !mp[mirror].empty())
            {
                result += (i-mp[mirror].top());
                mp[mirror].pop();
            }
            else {
                mp[c].push(i);
            }
        }
        return result; 
    }
};