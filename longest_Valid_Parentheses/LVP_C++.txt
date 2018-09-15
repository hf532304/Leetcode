class Solution {
public:
    int longestValidParentheses(string s) {   //use stack to check if the parentheses are well-formed. like LIS.
        int len = s.size();
        stack<int> S;                               
        int max = INT_MIN;
        int res = 0;
        int *count = NULL;                        //count is used to count the longest well-formed substring
        count = new int[len];
        for(int i = 0; i < len; i++){            //initialize the array.
            count[i] = 0;  
        }
        for(int i = 0; i < len; i++){
                if(s[i] == '('){
                    S.push(i);
                }
                else{
                    if(!S.empty()){                             //find the right parenthesis
                        int begin = S.top();
                        S.pop();
                        for(int j = begin; j < i; j++){
                                max = (max < count[j])? count[j] : max;          //to find if there are well-formed parentheses inside
                        }
                        count[i] += max;                     
                        max = 0;                                 //reinitialize
                        if(count[begin - 1] != 0){
                                count[i] += count[begin-1];         //to find if there are well-formed parentheses before i
                        }
                        count[i] += 2;
                    }
				}
		}
        for(int i = 0; i < len; i++){ 
            res = (res < count[i])? count[i] : res;               //to find the longest one
        }
        delete []count;             //free the memory
        return res;
	}
};