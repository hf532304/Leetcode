class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> Result = new ArrayList<List<Integer>>();
        int lowwer, higher, middle;
        lowwer = 0;
        Arrays.sort(nums);
        while(nums.length > 0 && nums[lowwer] <= 0 && lowwer < nums.length -2){
          higher = nums.length - 1;
          middle = lowwer + 1;
        while(middle < higher){
            int sum = nums[lowwer] + nums[middle] + nums[higher];
           if(sum == 0){
              List<Integer> OneofResult = new ArrayList<Integer>();
               OneofResult.add(nums[lowwer]);
               OneofResult.add(nums[middle]);
               OneofResult.add(nums[higher]);
               Result.add(OneofResult);
                middle++;
               higher--;
               while((nums[middle] == nums[middle - 1]) && middle < higher)
                    middle++;
               while((nums[higher] == nums[higher + 1]) && higher > middle )
                    higher--;
         }
        
            else if(sum < 0){
                middle++;
                while((nums[middle] == nums[middle - 1]) && middle < higher)
                    middle++;
          }
            else if(sum > 0) {
                higher--;
                while((nums[higher] == nums[higher + 1]) && higher > middle )
                    higher--;
            }
        }
            lowwer++;
            while(nums[lowwer] == nums[lowwer-1] && lowwer < higher)
                lowwer++;
        }
        return Result;
    }
}