class Solution {
public: 
	vector<vector<int>> combination(vector<int> nums, vector<vector<int>>& res, int sum, int target, vector<int>& One_res,int pos){
		for(int i = pos; i < nums.size()-1; i++){
			if(nums[i] == nums[i+1])
				continue;
			if(sum == target){
				res.push_back(One_res);
				break;
			}
			else if(sum > target){
				break;
			}
			else{
				One_res.push_back(nums[i]);
				combination(nums,res,sum + nums[i],target,One_res,i);
				One_res.pop_back();
			}
		}
		return res;
	}
	
	vector<vector<int>> combinationSum(vector<int> nums, int target){
		vector<vector<int>> res;
		vector<int> One_res;
		sort(nums.begin(),nums.end());
		return combination(nums,res,0,target,One_res,0);
	}
};
