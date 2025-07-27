class Solution {
    public int countHillValley(int[] nums) {
     ArrayList<Integer> arr1 = new ArrayList<>();
     ArrayList<Integer> arr2 = new ArrayList<>();
     
             for (int i = 0; i < nums.length; i++) {
            if (!arr1.isEmpty() && nums[i] == nums[i - 1]) {
                continue;
            }
            arr1.add(nums[i]);
        }

        
        System.out.println("arr1: " + arr1);
        int cnt = 0;
        for(int i=1;i<arr1.size() -1;i++)
        {
            if(arr1.get(i) > arr1.get(i-1) && arr1.get(i) > arr1.get(i+1))    cnt++;
            if(arr1.get(i) < arr1.get(i-1) && arr1.get(i) < arr1.get(i+1))    cnt++;
        }

        return cnt;

    }
}