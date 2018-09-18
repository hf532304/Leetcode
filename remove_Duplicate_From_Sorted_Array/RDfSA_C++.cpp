class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int con = 0;
        if(nums.size() == 0 )
            return 0;
        while(i < nums.size()){
            if(i < nums.size() - 1 && nums[i] == nums[i+1]){
                con++;
            }
            else{
                if(con > 0){
                    nums.erase(nums.begin()+ i-con+1,nums.begin() +i +1);
                    i = i - con;
                    con = 0;
                }
            }
            i++;
        }
        return nums.size();
    }
};