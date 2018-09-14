class DP {
public: 
int LIS(vector<int> s){
		vector<int> count;
		int index;
		for(int i = 0; i < s.size(); i++){
			index = binary_search(count,s[i]);
				if(index == count.size()){
					count.push_back(s[i]);
				}
				else{
					count[index] =  s[i];
				}
		}
		return count.size();
	}
int binary_search(vector<int>& arr, int target){
	if(arr.size() == 0)
			return 0;
	if(arr.size() == 1)
		return (arr[0] < target)? 1 : 0;
	int left = 0;
	int right = arr.size() - 1;
	while(left < right){
		int mid = (left + right + 1)/2;
		if(arr[mid] < target){
			left = mid;
		}
		else {
			right = mid -1;
		}
	}
	return left + 1;
	}
};
