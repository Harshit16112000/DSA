class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        int curr = 0;
        int temp = k;

        // change for north east
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'N' || s[i] == 'E')
            {
                if(temp > 0)
                {
                    temp--;
                    curr++;
                }
                else {
                    curr--;
                }
            }
            else 
              curr++;
            result = max(result, curr);
        }
        

        // Change for sout east
        curr = 0;
        temp = k;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'S' || s[i] == 'E')
            {
                if(temp > 0)
                {
                    temp--;
                    curr++;
                }
                else {
                    curr--;
                }
            }
            else 
                curr++;
            result = max(result, curr);
        }
        


        // Change for south west
        temp = k;
        curr = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'S' || s[i] == 'W')
            {
                if(temp > 0)
                {
                    temp--;
                    curr++;
                }
                else {
                    curr--;
                }
            }
            else {
                curr++;
            }
            result = max(result, curr);
        }
        

        // Change for north west
        temp = k;
        curr = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'N' || s[i] == 'W')
            {
                if(temp > 0)
                {
                    temp--;
                    curr++;
                }
                else {
                    curr--;
                }
            }
            else {
                curr++;
            }
            result = max(result, curr);
        }      
        return result;
    }
};