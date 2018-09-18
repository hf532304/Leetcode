class Solution {
public: 
	vector<vector<int>> combination(vector<int> nums, vector<vector<int>>& res, int sum, int target, vector<int>& One_res,int pos){
		for(int i = pos; i < nums.size(); i++){
			if(sum == target){
				res.push_back(One_res);
				break;
			}
			else if(sum > target){
				break;
			}
			else{
				if(i > 0 && nums[i] == nums[i-1] && pos!=i)
					continue;
				One_res.push_back(nums[i]);
				combination(nums,res,sum + nums[i],target,One_res,i+1);
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
