class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length -1;
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        int point = left;             //find the rotated point
        int low = 0;
        int high = nums.length -1;
        while(low <= high){
            int mid = (low + high)/2;
            int realmid = (mid + point)%(nums.length);
            if(nums[realmid] == target){
                return realmid;
            }
            else if(nums[realmid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
}