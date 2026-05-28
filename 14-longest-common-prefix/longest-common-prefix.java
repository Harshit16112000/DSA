class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        if (strs.length == 1) return strs[0];
        int mini=Integer.MAX_VALUE;
        int j=0;
        for(int i=1;i<strs.length;i++)
        {
        
            while(j < strs[0].length() && j < strs[i].length() && strs[0].charAt(j) == strs[i].charAt(j))
            {
                j++;
            }
            mini = Math.min(mini,j);
            j=0;
        }

        return strs[0].substring(0,mini);
    }
}