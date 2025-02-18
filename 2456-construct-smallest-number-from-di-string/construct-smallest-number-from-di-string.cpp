class Solution {
public:
    bool solve(vector<int> &subsequence, string &pattern, int index, vector<bool> &used)
     {
        if(index == subsequence.size())  return true;
        int prevIndex = subsequence[index-1];

        if(pattern[index-1] == 'I')
        {
            for(int i=prevIndex+1; i <= 9;i++)
            {
                if(used[i])  continue;
                used[i] = true;
                subsequence[index] = i;
                if(solve(subsequence, pattern, index+1, used)) return true;
                used[i] = false;
            }
        }

        else if(pattern[index-1] == 'D')
        {
            for(int i=prevIndex-1; i >= 1;i--)
            {
                if(used[i])  continue;
                used[i] = true;
                subsequence[index] = i;
                if(solve(subsequence, pattern, index+1, used)) return true;
                used[i] = false;
            }
        }

        return false;   

     }
     
    string smallestNumber(string pattern) {
        vector<int> subsequence(pattern.size() + 1, 0);
        vector<bool> used(10, false);
        for(int i=1;i<=9;i++)
        {
            subsequence[0] = i;
            used[i] = true;
            if(solve(subsequence, pattern, 1, used))  {
                string result;
                for (int num : subsequence) result += to_string(num);
                return result;
            }
            used[i] = false;
        }
        return "";
    }
};