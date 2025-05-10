class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = -1;
        long long sum1 = 0;
        long long cnt1 = 0;

        long long sum2 = 0;
        long long cnt2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            sum1 += nums1[i];
            if (nums1[i] == 0) {
                cnt1++;
                sum1++;
            }
        }

        for (int i = 0; i < nums2.size(); i++) {
            sum2 += nums2[i];
            if (nums2[i] == 0) {
                cnt2++;
                sum2++;
            }
        }

        long long mini = min(sum1, sum2);
        if(sum1 == sum2)  return sum1;
        if (mini == sum2 && cnt2 == 0)
            return -1;
        if (mini == sum1 && cnt1 == 0)
            return -1;

        long long maxi =  max(sum1, sum2);

        // if(maxi == sum2 && maxi - mini < cnt1)  return -1;
        // if(maxi == sum1 && maxi - mini < cnt2)  return -1;

        return maxi;
    }
};