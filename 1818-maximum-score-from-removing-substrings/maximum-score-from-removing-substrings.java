class Solution {
    public int maximumGain(String s, int x, int y) {
        // Always remove the more valuable substring first
        if (x > y) {
            return removeWithOrder(s, 'a', 'b', x, y); // remove "ab" first
        } else {
            return removeWithOrder(s, 'b', 'a', y, x); // remove "ba" first
        }
    }

    private int removeWithOrder(String s, char firstChar, char secondChar, int firstVal, int secondVal) {
        Stack<Character> st = new Stack<>();
        int totalScore = 0;

        int cnt = 0;
        int index = 1;
        st.push(s.charAt(0));

        while (index < s.length()) {
            if (!st.empty() && st.peek() == firstChar && s.charAt(index) == secondChar) {
                st.pop();
                cnt += firstVal;
            } else {
                st.push(s.charAt(index));
            }
            index++;
        }

        // Step 2: Remove second pattern from remaining characters

        // Now process "ba"
        int a = 0;
        while (!st.empty()) {
            char ch = st.pop();
            if (ch == firstChar) {
                a++;
            } else if (ch == secondChar) {
                if (a > 0) {
                    cnt += secondVal;
                    a--;
                }
            } else {
                a = 0;
            }
        }

        return cnt;

        
    }
}
