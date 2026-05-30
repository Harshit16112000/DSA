class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int ans[] = new int[temperatures.length];
         

        Stack<Pair<Integer,Integer>> st = new Stack<>();

        for(int i=temperatures.length-1;i>=0;i--)
        {
            if(st.empty())   ans[i] = 0;
            else if(!st.empty() && st.peek().getKey() > temperatures[i])
            {
                ans[i] = st.peek().getValue() - i;
            }
            else if(!st.empty() && st.peek().getKey() <= temperatures[i])
            {
                while(!st.empty() && st.peek().getKey() <= temperatures[i])
                {
                    st.pop();
                }
                if(st.empty())  ans[i] = 0;
                else   ans[i] = st.peek().getValue() -i;
            }
            st.push(new Pair<>(temperatures[i], i));
        }

        return ans;    
        }
    }
