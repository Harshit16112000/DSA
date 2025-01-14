class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int cnt = 0;
        vector<int> ans;
        for(int i=0;i<A.size();i++)
        {
            mp1[A[i]]++;
            mp1[B[i]]++;
            for(auto &[key,value] : mp1)
            {
                if(value%2 == 0 && value != 0) {
                    cnt++;
                    mp1[key] = 0;
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};