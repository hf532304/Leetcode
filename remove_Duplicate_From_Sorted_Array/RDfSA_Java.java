class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0; 
        int j = 1;
        if(nums.length == 0)
            return 0;
        while(i < nums.length && j < nums.length){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                j++;
            }
            else
                j++;
        }
        return i+1;
    }
}