class Solution {
public:
    int countLargestGroup(int n) {
     map<int,int> mpp;

     for(int i=1;i<=n;i++)
     {
        int num = i;
        int sum = 0;
        while(num > 0)
        {
            sum += num%10;
            num = num/10;
        }
        mpp[sum]++;
     }

     int cnt = 0;
     map<int,int> mpp2;
     for(auto &[key,value] : mpp)
       mpp2[value]++;

    auto lastIt = --mpp2.end(); 

return lastIt->second;   

   
    }
};