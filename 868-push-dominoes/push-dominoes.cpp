class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i = 0;

        while (i < n) {
            if (dominoes[i] == 'R') {
                int r = i;
                int l = r + 1;

                // Move l until we find an 'L' or end
                while (l < n && dominoes[l] == '.') l++;

                if (l < n && dominoes[l] == 'L') {
                    // R....L → balance
                    int left = r + 1;
                    int right = l - 1;

                    while (left < right) {
                        result[left++] = 'R';
                        result[right--] = 'L';
                    }
                    i = l + 1; // Skip ahead
                } else {
                    // R... or R....R
                    for (int k = r + 1; k < l; ++k) {
                        result[k] = 'R';
                    }
                    i = l; // Skip to the next unprocessed character
                }
            } else if (dominoes[i] == 'L') {
                int l = i - 1;
                while (l >= 0 && result[l] == '.') result[l--] = 'L';
                i++;
            } else {
                i++;
            }
        }

        return result;
    }
};
