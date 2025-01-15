class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        int result = 0;
        for(int i=31; i>=0 && setBits >0 ; i--)
        {
            if(num1 & (1 << i))
            {
                result |=  (1 << i);
                setBits--;
            }
        }

        for(int i=0;i<32 && setBits >0; i++)
        {
            if(!(result & (1 <<i)))
            {
                result |=  (1 << i);
                setBits--;
            }
        }

        return result;

    }
};