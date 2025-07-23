class Solution {
    public int maximumGain(String s, int x, int y) {
        int cnt1 = removeABThenBA(s, x, y);
        int cnt2 = removeBAThenAB(s, x, y);
        return Math.max(cnt1, cnt2);
    }

    // Follow your original approach: Remove "ab" then "ba"
    private int removeABThenBA(String s, int x, int y) {
        Stack<Character> st = new Stack<>();
        int cnt = 0;
        int index = 1;
        st.push(s.charAt(0));

        while (index < s.length()) {
            if (!st.empty() && st.peek() == 'a' && s.charAt(index) == 'b') {
                st.pop();
                cnt += x;
            } else {
                st.push(s.charAt(index));
            }
            index++;
        }

        // Now process "ba"
        int a = 0;
        while (!st.empty()) {
            char ch = st.pop();
            if (ch == 'a') {
                a++;
            } else if (ch == 'b') {
                if (a > 0) {
                    cnt += y;
                    a--;
                }
            } else {
                a = 0;
            }
        }

        return cnt;
    }

    // Follow your original approach: Remove "ba" then "ab"
    private int removeBAThenAB(String s, int x, int y) {
        Stack<Character> st = new Stack<>();
        int cnt = 0;
        int index = 1;
        st.push(s.charAt(0));

        while (index < s.length()) {
            if (!st.empty() && st.peek() == 'b' && s.charAt(index) == 'a') {
                st.pop();
                cnt += y;
            } else {
                st.push(s.charAt(index));
            }
            index++;
        }

        // Now process "ab"
        int a = 0;
        while (!st.empty()) {
            char ch = st.pop();
            if (ch == 'b') {
                a++;
            } else if (ch == 'a') {
                if (a > 0) {
                    cnt += x;
                    a--;
                }
            } else {
                a = 0;
            }
        }

        return cnt;
    }
}
