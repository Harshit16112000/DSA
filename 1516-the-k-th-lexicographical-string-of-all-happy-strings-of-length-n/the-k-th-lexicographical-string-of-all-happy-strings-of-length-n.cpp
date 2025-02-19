class Solution {
public:
    bool solve(int index, int& k, string& ans, int n)
    {
        if(index  == n)
        {
            k--;
            return k == 0;
        }
        char prevChar = ans[index-1]; 
        if(prevChar == 'a')
        {
            ans += 'b';
            if(solve(index+1, k,ans,n)) return true;

            ans.pop_back();

            ans += 'c';
            if(solve(index+1, k,ans,n)) return true;
            ans.pop_back();
        }
        else if(prevChar == 'b')
        {
            ans += 'a';
            if(solve(index+1, k,ans,n)) return true;
            ans.pop_back();

            ans += 'c';
            if(solve(index+1, k,ans,n)) return true;
            ans.pop_back();
        }
        else {
            ans += 'a';
            if(solve(index+1, k,ans,n)) return true;
            ans.pop_back();

            ans += 'b';
            if(solve(index+1, k,ans,n)) return true;
            ans.pop_back();
        }
        return false;
    }

    string getHappyString(int n, int k) {
        
        string ans = "";
        int cnt = k;
        
        ans += 'a';
        if(solve( 1,k, ans, n)) return ans;

        ans = "";
        ans += 'b';
        if(solve( 1,k, ans, n))  return ans;

        ans = "";
        ans += 'c';
        if(solve( 1,k, ans, n))   return ans;
        
        return "";
    }
};