class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        set<string> st;

        unordered_map<string, int> freq;
        unordered_map<char, int> mpp2;
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < words.size(); i++) {

            if(words[i][0] == words[i][1])
            {
                mpp2[words[i][0]]++;
                continue;
            }
            

            string rev = words[i];
            reverse(rev.begin(), rev.end());

            if (words[i] != rev && freq[rev] > 0) {
                freq[rev]--;
                cnt += 4;
            } else {
                freq[words[i]]++;
            }
        }

        for(auto &[key,value] : mpp2)
        {
            cout << key << value << " ";
            if(value%2 == 1 && flag == false)
            {
                cnt = cnt + (value * 2);
                flag = true;
            }
            else {
                if(value % 2 == 0 )
                   cnt = cnt + (value * 2);
                else {
                    cnt = cnt + ((value-1) * 2);
                }
            }
        }

        return cnt;
    }
};