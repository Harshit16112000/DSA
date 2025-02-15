class Solution {
public:
    vector<double> getArea(vector<vector<int>> &squares,  double mid)
    {
        double lower = 0;
        double upper = 0;

        for(auto &s: squares)
        {
            if(s[1] + s[2] <= mid)   lower += (double)s[2] * (double)s[2];
            else if(s[1] >= mid)     upper += (double)s[2] * (double)s[2];
            else {
                lower += (mid - (double)s[1]) * (double)s[2];
                double lowersquare = (mid - (double)s[1]) * (double)s[2];
                upper += (double)s[2] * (double)s[2] - lowersquare;
            }
        }

        return {lower, upper};
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;  double mid = 0; double high = 0;
        double ans = 0;
         high = INT_MAX;

        while(low <= high)
        {
            mid = (low) + (high-low)/2;
            vector<double> area = getArea(squares, mid);
            double lowerArea = area[0];
            double upperArea = area[1];

            if(ans == mid)  break;
            if(upperArea > lowerArea)  low = mid;
            else high = mid ;
            ans = mid;
        }

        return ans;
    }
};