class Solution {
public:
    bool solve(vector<int> &generateSubsequence, vector<bool> &used, int index, int n)
    {
        if(index == generateSubsequence.size())   return true;
        
        if (generateSubsequence[index] != 0) return solve(generateSubsequence, used, index + 1, n);
        
        for(int i=n ; i >=1;i--)
        {
            //if(used[i] == true)   continue;
            int nextIndex = 0;
            if(i ==1) nextIndex = index;
            else nextIndex = index + i;

            if(used[i] == true || nextIndex >= generateSubsequence.size() || generateSubsequence[nextIndex] != 0)  continue;
            used[i] = true;
            generateSubsequence[nextIndex] = i;
            generateSubsequence[index] = i;
            if(solve(generateSubsequence, used, index + 1, n)) return true;
            
            generateSubsequence[nextIndex] = 0;
            generateSubsequence[index] = 0;
            used[i] = false;
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> generateSubsequence(2*n-1,0);
        vector<bool> used(n+1, false);
        solve(generateSubsequence,  used , 0,  n);
        return generateSubsequence;
    }
};