class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int ans[] = new int[nums1.length];
        boolean flag = false;
        for(int i=0;i<nums1.length;i++)
        {
            ans[i] = -1;
            flag = false;
            for(int j=0;j<nums2.length;j++)
            {
                if(flag) {
                    if(nums1[i] < nums2[j])
                    {
                        ans[i] = nums2[j];
                        break;
                    }
                }
                if(nums1[i] == nums2[j])
                {
                    flag = true;
                }
            }
        }

        return ans;
    }
}