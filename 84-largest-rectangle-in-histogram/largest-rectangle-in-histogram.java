class Solution {
    public int largestRectangleArea(int[] heights) {
        // Next Smallest to Left index
        // Next Smallest to Right index

        int nsl[] = new int[heights.length];
        int nsr[] = new int[heights.length];

        Stack<Pair<Integer,Integer>> st = new Stack<>();
        for(int i=heights.length-1;i>=0;i--)
        {
            if(st.empty())  nsr[i] = heights.length;
            else if(!st.empty() && st.peek().getKey() < heights[i])
                    nsr[i] = st.peek().getValue(); 
            else if(!st.empty() && st.peek().getKey() >= heights[i])
            {
                while(!st.empty() && st.peek().getKey() >= heights[i])
                {
                    st.pop();
                }
                if(st.empty()) nsr[i] = heights.length;
                else nsr[i] = st.peek().getValue();
            }
            st.push(new Pair<>(heights[i],i));
        }

        Stack<Pair<Integer,Integer>> st2 = new Stack<>();
        for(int i=0;i<heights.length;i++)
        {
            if(st2.empty())  nsl[i] = -1;
            else if(!st2.empty() && st2.peek().getKey() < heights[i])
                    nsl[i] = st2.peek().getValue(); 
            else if(!st2.empty() && st2.peek().getKey() >= heights[i])
            {
                while(!st2.empty() && st2.peek().getKey() >= heights[i])
                {
                    st2.pop();
                }
                if(st2.empty()) nsl[i] = -1;
                else nsl[i] = st2.peek().getValue();
            }
            st2.push(new Pair<>(heights[i],i));
        }
        System.out.println("NSR");
        for(int i=0;i<nsr.length;i++)
        {
            System.out.print(nsr[i] + " ");
        }

        System.out.println("NSL");
        for(int i=0;i<nsl.length;i++)
        {
            System.out.print(nsl[i] + " ");
        }

        int maxi = 0;
        for(int i=0;i<nsl.length;i++)
        {
            maxi = Math.max(maxi, (nsr[i] - nsl[i] - 1) * heights[i] );
        }

        for(int i=0;i<heights.length;i++)
        {
            maxi = Math.max(heights[i], maxi);
        }
        return maxi;

    }
}