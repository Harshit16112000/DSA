class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        map<int,int> mpp;
        for(int i=0;i<elements.size();i++)
        {
            if(mpp.contains(elements[i]))  continue;
            mpp[elements[i]] = i;
        }
        vector<int> ans(groups.size(), INT_MAX);

        for(int i=0;i<groups.size();i++)
        {
            for(int j=1;j*j<=groups[i];j++)
            {
                if(groups[i]%j == 0)
                {
                    if(mpp.contains(j))
                    {
                        ans[i] = min(ans[i], mpp[j]);
                    }
                    if( mpp.contains(groups[i]/j))
                    {
                        ans[i] = min(ans[i], mpp[groups[i]/j]);
                    }
                }
            }
        }

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i] == INT_MAX)  ans[i] = -1;
        }

        return ans;
    }
};