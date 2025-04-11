class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++)
        {
            int cnt = countDigit(i);
            if(cnt%2 == 0)
            {
                int firsthalf = countSum(0, cnt/2,i);
                int secondhalf = countSum(cnt/2, cnt,i);
                //cout << i << secondhalf << " ";
                if(firsthalf == secondhalf)  ans++;
                
            }
        }
        return ans;
    }

    int countDigit(int num)
    {
        int cnt = 0;
        while(num > 0)
        {
            num = num/10;
            cnt++;
        }
        return cnt;
    }

    int countSum(int first, int second, int num)
    {
        int cnt = 0;
        int res = 0;
        //cout << first << second << " ";
        while(num > 0)
        {
            
            if(cnt >= first && cnt < second)
            {
                res += num%10;
            }
            num = num/10;       
            cnt++;
        }

        return res;
    }
};