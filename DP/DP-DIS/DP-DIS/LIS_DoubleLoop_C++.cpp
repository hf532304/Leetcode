class DP {
public: 
	int LIS(int s[],int edge){
		int res = 0;
		if(edge == 0)
			return 0;                 //check if s is empty
		int * count = new int[edge];
		for(int i = 0 ; i< edge ; i++){
			count[i] = 1;
		}
		for(int i = 0; i < edge; i++){
			for(int j = 0; j < i; j++){
				count[i] = (s[j]<=s[i])? max(count[j] + 1, count[i]) : 1;
			}
		}
		for(int i = 0 ; i< edge ; i++){
			max = (max < count[i])? count : max;
		}
		delete []count;                  //free the memory
		return max;
	}
};
