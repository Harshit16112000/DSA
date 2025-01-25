class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> charFrequencyMap;
        for (char currentChar : s) {
            charFrequencyMap[currentChar]++;
        }

        // Step 2: Calculate the number of characters to delete
        int cnt = 0;
        for (auto& pair : charFrequencyMap) {
            int frequency = pair.second;
            if (frequency % 2 == 1) {
                // If frequency is odd, delete all except one
                cnt++;
            } else {
                // If frequency is even, delete all except two
                cnt = cnt+2;
            }
        }

        return cnt;
    }
};