class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> pSum(s.size() + 1, 0);

        for (int i = 0; i < shifts.size(); i++) 
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];

                if (dir == 0) {
                    pSum[start] += -1;
                    pSum[end+1] += 1;
                }   
                else {
                    pSum[start] += 1;
                    pSum[end+1] += -1;
                }    
        }
        for(int i=1;i<pSum.size();i++)
        {
            pSum[i]+= pSum[i-1] % 26;
        }
        
        for (int i = 0; i < s.size(); i++) {
            int shift = pSum[i] % 26;  // Modulo operation to wrap around alphabet
            if (shift < 0) shift += 26;  // Ensure positive shift

            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};