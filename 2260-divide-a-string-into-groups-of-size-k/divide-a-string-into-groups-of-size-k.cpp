class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        string str = "";
        for(int i=0;i<s.size();i++)
        {
            if(str.size() == k)
            {
                result.push_back(str);
                str = "";
            }
            str += s[i]; 
        }

        while(str.size()  != k)
        {
            str += fill;
        }
        result.push_back(str);
        return result;
    }
};