class DP {
public: 
int LCS(vector<int> s1, vector<int> s2){
	int **arr = new int*[s1.size() + 1];
	for(int i = 0; i< s1.size()+1; i++)
	arr[i] = new int[s2.size() + 1];
	for(int i = 0; i < s1.size() + 1; i++){
		for(int j = 0 ; j < s2.size() + 1; j++){
			arr[i][j]=0;
		}
	}
	for(int i = 1; i < s1.size() + 1; i++){
		for(int j = 1 ; j < s2.size() + 1; j++){
			if(s1[i-1] == s2[j-1]){
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else{
				arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
			}
		}
	}
	return arr[s1.size()][s2.size()];
}
};
