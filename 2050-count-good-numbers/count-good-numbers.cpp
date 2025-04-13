class Solution {
public:
     const int MOD = 1e9 + 7;
     long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }


    int countGoodNumbers(long long n) {
        long long cntodd = n/2;
        long long cnteven = n - n/2;

        return power(5, cnteven) % MOD * power(4, cntodd) % MOD;
        
    }
};