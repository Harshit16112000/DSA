class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> st = new Stack<>();
        String ans = "";
        for(int i=0;i<s.length();i++)
        {
            
            if( !st.empty() && st.peek() == s.charAt(i))
            {
                st.pop();
                continue;
            }
            st.push(s.charAt(i));
        }

        while(!st.empty())
        {
            ans += st.peek();
            st.pop();
        }

        return new StringBuilder(ans).reverse().toString();

    }
}