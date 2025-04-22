class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int maxi = 0;
        for(int i=0;i<k;i++)
        {
            sum += cardPoints[i];
        }
        int l = cardPoints.size() - 1;
        int r = k;
         maxi = sum;
        while(r > 0)
        {
            sum = sum + cardPoints[l] - cardPoints[r-1];
            maxi = max(maxi, sum);
            l--;
            r--;
        }
        return maxi;
    }
};