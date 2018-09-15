class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res = false;
        int Size = nums.size();
        int maxlength = 0;
        if(Size < 2){
            return true;
        }
        for(int i = 0; i < Size; i++){
            if(nums[i] == 0){                          // if maxlength could get over 0
                if(maxlength > i){
                    continue;
                }
                else{
                    return false;
                }
            }
            maxlength = (maxlength < (nums[i] + i))? nums[i] + i : maxlength;    //get the largest index
            if(maxlength >= Size - 1){
                return true;
            }    
        }
        return res;
    }
};