class Solution {
public:
    int divide(int dividend, int divisor) {
        int rest = 0;        //for the rest
        int res = 0;
        int digit = 1;           //a moving bit
        bool flag = true;        //for sign
        bool Edge = false;
        if(dividend < 0)
            flag = !flag;
        if(divisor < 0)
            flag = !flag;
        if(divisor == 0) return -1;        // for edge case
        if(dividend == 0) return 0;
        if(divisor == INT_MIN){
            return dividend == INT_MIN? 1 : 0;
        }
        if(dividend == INT_MIN){
            Edge = true;
            if(divisor == -1)
                return INT_MAX;
            else if(divisor == 1)
                return INT_MIN;
            else{
                dividend = INT_MIN + 1;
            }
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        int did = dividend;
        while(did != 1){          //get the highest bit
            did = did >> 1;
            digit = digit << 1;
        }
        while(digit != 0){
            rest = rest + rest;
			rest += ((dividend & digit) > 0)? 1 : 0;// get the rest
            if(rest < divisor){
                res = res + res;
            }
            else{
                rest = rest - divisor;
                res = res + res + 1;
            }
            digit = digit >> 1;
        }
        if(Edge && rest + 1 == divisor)
            res ++;
        return (flag == true)? res : -res;
    }
};