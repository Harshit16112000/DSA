class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> st;
        for(int i=0;i<n;i++)
        {
            string str = words[i];
            for(int j=0;j<n;j++)
            {
                if(i !=j)
                {
                    if( words[j].find(str) != -1)
                    st.insert(str);
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};