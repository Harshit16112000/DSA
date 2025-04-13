class Solution {
public:
     const int MOD = 1e9 + 7;
     long long power(long long x, long long power) {
        long long result = 1;
       while(power > 0)
        {
            if(power%2 == 1)
            {
                result = (result * x) % MOD;
                power = power-1;
            }
            else 
            {
                power = power/2;
                x = (x * x) % MOD;
            }
        }
        return result;
    }


    int countGoodNumbers(long long n) {
        long long cntodd = n/2;
        long long cnteven = n - n/2;

        return power(5, cnteven) % MOD * power(4, cntodd) % MOD;
        
    }
};