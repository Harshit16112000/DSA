class Solution {
public:
    vector<int> Kmp(string s)
    {
        vector<int> lps(s.size(), 0 );

        for(int i=1;i<s.size();i++)
        {
            int prevIndx = lps[i-1];
            while(prevIndx > 0 && s[i] != s[prevIndx])
               prevIndx = lps[prevIndx - 1];

            lps[i] = prevIndx + (s[i] == s[prevIndx] ? 1 : 0);
        }
        return lps;

    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string s = "";

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
               s.push_back('b');
            else if(nums[i] == nums[i-1])
               s.push_back('a');
            else
                s.push_back('c');
        }

        string p = "";
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i] == 1)   p.push_back('b');
            else if(pattern[i] == 0)   p.push_back('a');
            else  p.push_back('c'); 
        }
        string s1 = p +'#' + s;
        vector<int> lps = Kmp(s1);

        int cnt = 0;
        for(int i=0;i<lps.size();i++)
        {
            if(lps[i] == pattern.size())  cnt++;
        }
        return cnt;
    }

};