class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int i = 0;
        int p = part.size();
        while (i < s.size()) {
            st.push(s[i]);
            if (st.size() >= p) {

                string temp = "";
                for (int j = p - 1; j >= 0; j--) {
                    temp = st.top() + temp;
                    st.pop();
                }

                if (temp != part) {
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }
            }

            i++;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};