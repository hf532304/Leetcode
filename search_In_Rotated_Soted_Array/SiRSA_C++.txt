class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int flag = 0;
        if(right == -1)
            return -1;
        if(nums[right] > nums[left]){
            flag = 1;
        }
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(flag || target >= nums[0]){
                if(nums[mid] > target){
                    right = mid - 1;
                }
                else{                  //nums[mid] <= target
                    if(flag || nums[mid] >= nums[0]){
                       left = mid + 1;
                    }
                    else{
                        right = mid -1;
                    }
                }
            }
            else{                       //target < nums[0]
                if(nums[mid] > target){
                    if(nums[mid] <= nums[nums.size()-1]){
                        right = mid - 1;
                    }
                    else{               //nums[mid] > nums[nums.size()-1]
                        left = mid + 1;
                    }
                }
                else{                     //nums[mid] <= target
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};