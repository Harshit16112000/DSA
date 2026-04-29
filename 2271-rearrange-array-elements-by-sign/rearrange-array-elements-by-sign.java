class Solution {
    public int[] rearrangeArray(int[] nums) {
        ArrayList<Integer> pos = new ArrayList<>();
        ArrayList<Integer> neg = new ArrayList<>();
        
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] > 0)
                pos.add(nums[i]);
            else
                neg.add(nums[i]);
        }

        
        int[] result = new int[nums.length];
        int index = 0;
        int i=0;
        while(i < nums.length)
        {
            result[i] = pos.get(index);
            i++;
            result[i] = neg.get(index);
            i++;
            index++;
        }
        return result;
    }
}