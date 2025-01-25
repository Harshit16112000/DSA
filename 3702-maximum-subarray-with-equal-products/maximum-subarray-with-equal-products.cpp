class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int lcd(int a, int b) { 
        return (a / gcd(a, b)) * b;; 
    }

    int result = 0;
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int gc = nums[i];
            int lc = nums[i];
            long long  product = nums[i]; 
            
            for (int j = i + 1; j < n; j++) {
                
                gc = gcd(gc, nums[j]);
                lc = lcd(lc, nums[j]);
                if (product  > LLONG_MAX / nums[j] ) {
                    break; // Avoid overflow
                }
                product *= (nums[j]);
                if(product == 1LL * gc * lc)  
                result = max(result,j-i+1);
            }
        }
        return result;
    }
};