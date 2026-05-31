class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ']') {

                // Step 1 — collect characters until '['
                String encodedString = "";
                while (stack.peek() != '[') {
                    encodedString += stack.pop();
                }
                String decodedString = new StringBuilder(encodedString).reverse().toString();
                stack.pop(); // pop '['

                // Step 2 — collect full repeat count (can be multi-digit)
                String repeatCountStr = "";
                while (!stack.empty() && Character.isDigit(stack.peek())) {
                    repeatCountStr = stack.pop() + repeatCountStr;
                }
                int repeatCount = Integer.parseInt(repeatCountStr);

                // Step 3 — repeat the decoded string
                String repeatedString = decodedString.repeat(repeatCount);

                // Step 4 — push back for nesting
                for (char ch : repeatedString.toCharArray()) {
                    stack.push(ch);
                }

            } else {
                stack.push(s.charAt(i));
            }
        }

        // Step 5 — build final result from stack
        String finalResult = "";
        while (!stack.empty()) {
            finalResult = stack.pop() + finalResult;
        }
        return finalResult;


    }
}


//My Mistake --> Didn't analysis step 4
//result += temp2;
// Works for flat:    3[a]2[b]  → "aaabb" ✓
// Fails for nested: 2[3[a]]
//
// When inner ] hit → temp2="aaa" → result="aaa"
// When outer ] hit → stack has nothing to collect
//                    inner "aaa" already lost into result ✗
//
// Fix: push temp2 back to stack
// So outer ] can collect it along with other chars