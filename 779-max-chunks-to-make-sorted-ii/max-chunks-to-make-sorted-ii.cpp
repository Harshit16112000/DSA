class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      int rmin[n+1];
      rmin[n] = INT_MAX;

      for(int i=n-1;i>=0;i--)
      {
        rmin[i] = min(rmin[i+1],arr[i]);
      }
      int cnt = 0;
      int leftMax = 0;
      for(int i=0;i<n;i++)
      {
        leftMax = max(arr[i], leftMax);
        if(leftMax <= rmin[i+1]) cnt++;
      }
      return cnt;
    }
};