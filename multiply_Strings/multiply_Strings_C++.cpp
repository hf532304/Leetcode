class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_len = num1.length();
        int num2_len = num2.length();
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int *count = new int[num1_len + num2_len];
        for(int i = 0; i < num1_len + num2_len; i++){
            count[i] = 0;
        }
        for(int i = num1_len -1; i >= 0; i--){
            for(int j = num2_len -1; j >= 0; j--){
                int mul1 = num1[i] - '0';
                int mul2 = num2[j] - '0';
                int sum = mul1 * mul2;
                count[i+j+1] += sum % 10;
                count[i+j] += sum /10;
            }
        }
        for(int i = num1_len + num2_len-1; i >=1 ; i--){
            count[i-1] += count[i] / 10 ;
            count[i] %=10;
        }
        string res ="";
        bool flag = 0; //for first 0-chain
        for(int i = 0; i < num1_len + num2_len; i++){
            if(!flag && count[i] == 0){
                continue;
            }
            else{
                flag =1;
                res += (count[i] != -1)? char(count[i]+'0') : char(0);            
            }
        }
        return res;
    }
};