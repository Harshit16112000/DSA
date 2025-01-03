class Solution {
public:
    bool checkDays(int ele, vector<int>& weights, int days) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];

            // Went wrong with this inner if block, placed the inner block, outside if block.
            if (sum > ele) {
                cnt++;
                sum = weights[i];
                if (cnt > days)
                return false;
            }    
        }
        return true;
    }

    int splitArray(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            high += weights[i];
        }

        int ans = 0;
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (checkDays(mid, weights, days)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};