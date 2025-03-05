class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 0;
        long long result = 1;
        while(n!=1)
        {
            ans += 4;
            result += ans;
            n--;
        }
        return result;
    }
};