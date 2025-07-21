class Solution {
    public String makeFancyString(String s) {
        StringBuilder res = new StringBuilder();
        int cnt = 0;
        for(int i=0;i<s.length() -1;i++)
        {
            if(s.charAt(i) == s.charAt(i+1))
            {
                cnt++;
                if(cnt >= 2)  {
                    cnt--;
                    continue;
                }
                res.append(s.charAt(i));

            }
            else {
                 res.append(s.charAt(i));
                cnt = 0;
            }
        }

        if(cnt >= 2)  return res.toString();

    
        return res.append(s.charAt(s.length() - 1)).toString();
        
    }
}