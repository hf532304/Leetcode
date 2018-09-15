class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> Results;
        vector<int> Onesolution;
        unordered_map<int, int> Hash;
        int third_num_value;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size; i++)
            Hash[nums[i]] = i;
        for(int first_num = 0; first_num < size - 2 && nums[first_num] <=0; first_num++){
            for(int second_num = first_num + 1; second_num < size-1; second_num++){
                third_num_value = -(nums[first_num] + nums[second_num]);
                if(Hash.find(third_num_value) != Hash.end() && Hash.at(third_num_value) > second_num){
                    Onesolution.push_back(nums[first_num]);
                    Onesolution.push_back(nums[second_num]);
                    Onesolution.push_back(third_num_value);
                    Results.push_back(Onesolution);
                    Onesolution.clear();
                    while(nums[second_num] == nums[second_num+1])
                        second_num++;
                }
            } 
             while(nums[first_num] == nums[first_num+1])
                first_num++;
        }
        return Results;
    }
};