class Solution {
public: 
	vector<vector<int>> combination(vector<vector<int>>& res, int sum, int target, vector<int>& One_res,int pos,int cur){
		for(int i = pos; i < 10; i++){
			if(sum == target && cur == 0){
				res.push_back(One_res);
				break;
			}
			if(sum > target){
				break;
			}
			else{
				One_res.push_back(i);
				combination(res,sum + i,target,One_res,i+1,cur-1);
				One_res.pop_back();
			}
		}
		return res;
	}
	
	vector<vector<int>> combinationSum(int nums, int target){
		vector<vector<int>> res;
		vector<int> One_res;
		return combination(res,0,target,One_res,1,nums);
	}
};
