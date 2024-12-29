class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";
        if(numFriends == 1)
            return word;
            
        int n = word.size();
        int wordLimit = n - (numFriends - 1);
        
        string str;
        int i=0, j=0;

        while(j < wordLimit)
        {
            str += word[j];
            ans = max(ans, str);
            j++;
        }
        
        while(j < n)
        {
            str.erase(0,1);
            
            str+= word[j];
            j++;
            i++;
            ans = max(ans, str);
        }
        

       for (int i = 0; i <str.size(); ++i) {
            string sub = str.substr(i, n - i);
            ans = max(ans, sub);
        }

        


        return ans;

    }
};