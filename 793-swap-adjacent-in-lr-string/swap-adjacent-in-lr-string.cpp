class Solution {
public:
    void skipX(string &s, int &ind)
    {
        while(ind < s.size() && s[ind] == 'X') ind++;
    }
    bool canTransform(string start, string result) {
        int n = start.size();
        int i = 0;
        int j = 0;

        while(i < n && j < n)
        {
            skipX(start,i);
            skipX(result,j);

            if(i == n && j == n)  return true;
            if(i == n || j == n)  return false;

            if(start[i] != result[j])  return false;

            if(start[i] == 'L' && j >i)  return false;
            if(start[i] == 'R' && i > j)  return false;
            i++;
            j++;
        }

        skipX(start,i);
        skipX(result,j);

        return i == n && j == n;
    }
};