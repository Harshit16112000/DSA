class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> hmap = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        int result[] = new int[nums1.length];

        for(int i=nums2.length-1;i>=0;i--)
        {
            if(st.empty())   hmap.put(nums2[i], -1);
            else if(!st.empty() && st.peek() > nums2[i])
            {
                hmap.put(nums2[i], st.peek());
            }
            else if(!st.empty() && st.peek() < nums2[i])
            {
                while(!st.empty() && st.peek() < nums2[i])
                {
                    st.pop();
                }
                if(st.empty())  hmap.put(nums2[i], -1);
                else   hmap.put(nums2[i], st.peek());
            }
            st.push(nums2[i]);

        }

        for(int i=0;i<nums1.length;i++)
        {
            result[i] = hmap.get(nums1[i]);
        }
        return result;
    }
}