class Solution {
public:
    void skipDot(string& s, int& ind) {
        while (ind < s.size() && s[ind] == '_') {
            ind++;
        }
    }

    bool canChange(string start, string target) {
        int first = 0, second = 0;
        int n = target.size();

        while (first < n && second < n) {
            // Skip underscores in both strings
            skipDot(start, first);
            skipDot(target, second);

            // If both pointers reach the end, the transformation is valid
            if (first == n && second == n) return true;

            // If one pointer reaches the end but the other doesn't, invalid
            if (first == n || second == n) return false;

            // Check if characters match
            if (start[first] != target[second]) return false;

            // Validate 'L' movement
            if (start[first] == 'L' && second > first) return false;

            // Validate 'R' movement
            if (start[first] == 'R' && first > second) return false;

            // Move both pointers forward
            first++;
            second++;
        }

        // Ensure all remaining characters in both strings are underscores
        skipDot(start, first);
        skipDot(target, second);

        return first == n && second == n;
    }
};
