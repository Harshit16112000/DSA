class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        int j = 0;

        while(i< str1.size() && j < str2.size())
        {
            if(str1[i] == str2[j]) {
                j++;
            }
            
            else if(str1[i] == 'z')
            {
                if(str2[j] == 'a') j++;
            }
            else {
                if(str1[i] +1 == str2[j])   j++;
            }
            i++;
        }
          return j == str2.size();;
    }
};