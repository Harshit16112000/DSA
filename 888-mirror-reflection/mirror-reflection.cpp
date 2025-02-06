class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(p ==0 || q == 0)  return 0;

        int flag = true;
        int finap = p;
        int ans = 0;
        int posflag = true;
        while(true)
        {
            if(posflag)
                    ans += q;
                else
                    ans -= q;
           if(ans == p)   break;

           if(ans > p)  { 
            ans = p - ( ans - p);
            posflag = false;
           }

           if(ans == 0)  return 0;
           
           if(ans < 0)
           {
                posflag = true;
                ans =  -ans;
           }
           
           flag = !flag;
        }

        if(flag == true)  return 1;
        return 2;
    }
};