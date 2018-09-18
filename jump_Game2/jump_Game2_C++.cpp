class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int Size = nums.size();
        if(Size < 2){           //for edge case
            return 0;
        }
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[0]);
        int max_len = INT_MIN;
        while(dp[dp.size()-1] < Size - 1){
            for(int i = dp[dp.size() - 2]; i <= dp[dp.size() - 1]; i++){
                max_len = (max_len < (i + nums[i]))? (i+nums[i]) : max_len;
            }
            dp.push_back(max_len);
        }
        return dp.size() - 1;
    }
};