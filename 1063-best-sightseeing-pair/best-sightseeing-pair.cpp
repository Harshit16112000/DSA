class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeftScore = values[0];
        int maxScore = 0;

        for(int i=1;i<values.size();i++)
        {
            maxScore = max(maxScore, maxLeftScore + values[i] - i);
            maxLeftScore = max(maxLeftScore, values[i] + i);
        }
        return maxScore;
    }
};