class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int ans[] = new int[nums2.length];
        HashMap<Integer,Integer> hmap = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        int result[] = new int[nums1.length];

        for(int i=nums2.length-1;i>=0;i--)
        {
            if(st.empty())   ans[i] = -1;
            else if(!st.empty() && st.peek() > nums2[i])
            {
                ans[i] = st.peek();
            }
            else if(!st.empty() && st.peek() < nums2[i])
            {
                while(!st.empty() && st.peek() < nums2[i])
                {
                    st.pop();
                }
                if(st.empty())  ans[i] = -1;
                else   ans[i] = st.peek();
            }
            st.push(nums2[i]);

        }

        for(int i=0;i<nums2.length;i++)
        {
            hmap.put(nums2[i], ans[i]);
        }

        for(int i=0;i<nums1.length;i++)
        {
            result[i] = hmap.get(nums1[i]);
        }
        return result;
    }
}