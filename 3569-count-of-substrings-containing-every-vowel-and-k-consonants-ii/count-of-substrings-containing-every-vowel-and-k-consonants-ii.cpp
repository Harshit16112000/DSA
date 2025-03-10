class Solution {
public:
    long long countAtLeastK(const string& word, int k) {
        long long validCount = 0;
        int left = 0, right = 0;
        unordered_map<char, int> mpp;  // Single map for vowels + consonants
        int vowelCount = 0;  // Track how many distinct vowels are present

        while (right < word.length()) {
            char ch = word[right];

            if (isVowel(ch)) {
                if (++mpp[ch] == 1) vowelCount++;  
            } else {
                mpp['b']++;  
            }

            while (vowelCount == 5 && mpp['b'] >= k) {
                validCount += word.length() - right; 

                char leftChar = word[left];
                if (isVowel(leftChar)) {
                    if (--mpp[leftChar] == 0) {
                        mpp.erase(leftChar);
                        vowelCount--;  
                    }
                } else {
                    if (--mpp['b'] == 0) {
                        mpp.erase('b');
                    }
                }
                left++;  // Shrink window
            }

            right++;
        }
        return validCount;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }
};
