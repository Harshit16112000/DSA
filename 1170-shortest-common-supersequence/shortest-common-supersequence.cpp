class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        
      string str="";
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));  
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
         
        int i=m;
        int j=n;
        
         while(i>0 && j>0){
             if(text1[i-1]==text2[j-1]){
                 str=text1[i-1]+str;
                 i--;j--;
             }else{
                 if(dp[i][j-1]>=dp[i-1][j]){
                     str=text2[j-1]+str;
                     j--;
                 }else{
                     str=text1[i-1]+str;
                     i--;
                 }
             }
         }
         
         while(i>0){
             str=text1[i-1]+str;
             i--;
         }
         while(j>0){
             str=text2[j-1]+str;
             j--;
         }
         
        return str;
    }
};