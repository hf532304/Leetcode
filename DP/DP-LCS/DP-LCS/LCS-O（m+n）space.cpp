class DP {
public: 
int LCS(vector<int> s1, vector<int> s2){		//space-saving LCS
	if(s1.size() == 0 || s2.size() == 0)
		return 0;
	int m = 0;
	int **arr = new int*[s1.size() + 1];
	for(int i = 0; i< s1.size()+1; i++)
		arr[i] = new int[2];
	for(int i = 0; i < s1.size() + 1; i++){
		for(int j = 0 ; j < 2; j++){
			arr[i][j]=0;
		}
	}
	while(m < s2.size()){							//use DP to get the result
		for(int i = 1; i < s1.size() + 1; i++){
			if(s1[i-1] == s2[m]){
				arr[i][1] = arr[i-1][0] + 1;
			}
			else{
				arr[i][1] = max(arr[i-1][1],arr[i][0]);
			}
		}
		for(int i = 1; i < s1.size() + 1; i++){
			arr[i][0] = arr[i][1];
			arr[i][1] = 0;							// reset the window
		}
		m++;
	}
	return arr[s1.size()][0];
}
};
