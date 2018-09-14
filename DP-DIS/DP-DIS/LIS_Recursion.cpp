class DP {
public: 
	int LIS(int s[],int count[], int cur,int edge){
		if(edge == 0)
			return 0;
		for(int i = 0; i< cur; i++){
			if(cur == edge)
				return count[edge - 1];
			count[cur] = (s[i] <= s[cur])? max(count[i] + 1, count[cur - 1]) : count[cur-1];
		}
		return LIS(s,count,cur+1,edge);
	}
};
