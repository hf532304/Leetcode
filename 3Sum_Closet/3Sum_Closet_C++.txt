class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int Size = nums.size();
        int res;
        int dis = 65535;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < Size - 2; i++){
            int j = i + 1;
            int k = Size - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(dis> abs(target - sum)){
                    dis = abs(target - sum);
                    res = sum;
                }
                if(target == sum)    
                    return target;
                else if (target > sum)    
                    j++;
                else if (target < sum)  
                    k--;
                }
          }
          return res;
    }
};