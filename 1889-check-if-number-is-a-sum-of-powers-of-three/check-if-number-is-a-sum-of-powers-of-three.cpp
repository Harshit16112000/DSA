class Solution {
public:
    bool checkPowersOfThree(int n) {
     int num = 1;
     int prevvalue = 1;
    //  while(n!=0)
    //  {
    //     int powerof3 = pow(3, num);
    //     num++;
    //     if(powerof3 > n)
    //         {
    //             n = n - prevvalue;
    //             if(n < 0) return false;
    //         }
    //     prevvalue = powerof3;  
    //  }

    while (n > 0) {
            if (n % 3 == 2) return false; // If n has '2' in its base-3 representation, return false
            n /= 3; // Move to the next power of 3
        }
        
        return true;

     return true;   
    }
};