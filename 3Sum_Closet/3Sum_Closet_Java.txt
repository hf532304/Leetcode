class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int upper_border = nums.length;
        if(nums.length < 3)
            throw new IllegalArgumentException("the size of nums is too small");
        Arrays.sort(nums);
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.length - 2; i++){
            for(int j = i + 1; j < nums.length-1; j++){
               for(int k = j + 1; k < upper_border; k++){
                   int sum = nums[i] + nums[j] + nums[k];
                   if(target < sum){
                       if(Math.abs(target - res) > sum - target){
                           res = sum;
                       }
                       upper_border = k + 1;
                       break;
                   }
                   else if(target > sum){
                       if(Math.abs(target - res) > target - sum){
                                res = sum;
                       }
                   }
                   else
                       return sum;
               } 
            }            
        }
          return res;      
    }
}