class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> matchA;
        vector<int> matchB;

        for(int i=0;(i+a.size()) <= s.size();i++)
        {
            if(s.substr(i,a.size()) == a)      matchA.push_back(i);
        }
        for(int i=0;(i+b.size()) <= s.size();i++)
        {
            if(s.substr(i,b.size()) == b)      matchB.push_back(i);
        }
        
        vector<int>result;
        for(int i=0;i<matchA.size();i++)
        {
            auto it = lower_bound(matchB.begin(), matchB.end(), matchA[i]-k);
            
            // If b matrix is not zero, so, we needed it
            if ((it != matchB.end())  && (abs(*it - matchA[i]) <= k) ) result.push_back(matchA[i]);
        }
        return result;
    }
};
