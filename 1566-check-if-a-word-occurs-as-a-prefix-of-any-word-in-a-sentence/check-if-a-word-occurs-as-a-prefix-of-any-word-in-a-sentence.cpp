class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
       int cnt = 1;
       string sent = "";
       for(int i=0;i<sentence.size();i++)
       {
          
            if(sentence[i] == ' ')
            {
                sent = "";
                cnt++;
                continue;
            }
            sent += sentence[i];
            if(searchWord == sent)  return cnt;
       }
       return -1; 
    }
};