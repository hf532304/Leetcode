class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int flag_w = 1;                 //flag for whitespace
        int flag_s = 1;                 //flag for sign
        int sign = 1;
        for(char each : str){
            if(each == ' ' && flag_w){      //only ignore the front whitespace
                continue;
            }
            else{
                flag_w = 0; //stop scan for whitespace
                if(each == '-' && flag_s){
                    flag_s = 0;
                    sign = -1;
            }
                else if(each == '+' && flag_s){
                    flag_s = 0;
            }
                else if(each <= '9' && each >= '0'){
                    flag_s = 0;
                    if(sign > 0 && (INT_MAX / 10.0 < res || INT_MAX - 10 * res < (each-'0')))
                        return INT_MAX;
                    else if(sign < 0 &&(INT_MIN / 10.0 > res || INT_MIN - 10 * res > -(each-'0')))
                        return INT_MIN;
                    res = res * 10 + (sign * (each - '0'));
                }
                else {
                    return res;
                } 
            }
        }
        return res;
    }
};