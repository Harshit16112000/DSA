class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffMax(n,0);
        suffMax[n-1] = height[height.size() -1];

        for(int i=n-2;i>=0;i--)
        {
            suffMax[i] = max(suffMax[i+1], height[i]);
        }

        int left = height[0];
        int total = 0;
        for(int i=0;i<n;i++)
        {
            left = max(left, height[i]);
            if(height[i] < min(left, suffMax[i]))
            total += min(left, suffMax[i]) - height[i];
        }

        return total;


    }
};