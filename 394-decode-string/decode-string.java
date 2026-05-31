class Solution {
    public String decodeString(String s) {
       Stack<Character> st = new Stack<>(); 
       String result = "";
       for(int i=0;i<s.length();i++)
       {
            if(s.charAt(i) == ']')
            {
                
                String temp = "";
                while(st.peek() != '[')
                {
                        
                        temp += st.pop();
                        
                }
                String tempreverse = new StringBuilder(temp).reverse().toString();
                st.pop();
                String numStr = "";
                while (!st.empty() && Character.isDigit(st.peek())) {
                    numStr = st.pop() + numStr;   //reverses digits
                }
                int num = Integer.parseInt(numStr);

                String temp2 = tempreverse;
                
                while(num != 1)
                {
                    temp2 += tempreverse;
                    num--;
                }
                for (char c : temp2.toCharArray()) {
                    st.push(c);
                }  
                
            }
            else {
            st.push(s.charAt(i));
            }
            
       }
        while (!st.empty()) {
            result = st.pop() + result;  
        }
        return result;
    }
}