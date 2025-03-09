class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt = 0;
        int n = colors.size();
         colors.insert(colors.end(), colors.begin(), colors.end());
        for(int i=1;i<=n;i++)
        {
            if(colors[i-1] != colors[i] && colors[i+1] != colors[i])
            cnt++;
        }
        return cnt;

    }
};