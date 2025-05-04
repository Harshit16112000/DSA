class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt = 0;
        map<int,int> mpp;

        for(int i=0;i<dominoes.size();i++)
        {
            int a = min(dominoes[i][0], dominoes[i][1]);
            int b = max(dominoes[i][0], dominoes[i][1]);

            int key = a * 10 + b; // Encode pair uniquely

            cnt += mpp[key];
            mpp[key]++;
             
        }

        

        return cnt;
    }
};