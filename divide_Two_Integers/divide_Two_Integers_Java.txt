class Solution {
    public int divide(int dividend, int divisor) {
        int res = 0;           // for result
        boolean min = false;
        if(dividend == Integer.MIN_VALUE){
            if(divisor == Integer.MIN_VALUE)
                return 1;
            else if(divisor == 1){
                return Integer.MIN_VALUE;
            }
            else if(divisor == -1){
                return Integer.MAX_VALUE;
            }
            else{
                dividend = Integer.MIN_VALUE + 1;
                min = true;
            }
        }
        if(divisor == 0){
            return -1;
        }
        if(divisor == Integer.MIN_VALUE){             //above for edge cases
            return 0;
        }
        int sign = ((dividend < 0) ^ (divisor < 0))? -1 : 1;   // for sign
        int did = Math.abs(dividend);
        int div = Math.abs(divisor);
        int base = 1; // a moving bit
        while(did >= (div * (base << 1))){
            base <<= 1;
            if(INT_MAX - did
        }
        while(did >= div){
            if(did >= div * base){
                did -= div * base;
                res += base;
            }
            base >>= 1;
        }
        if(min && did + 1 == div){
            res++;
        }
        return (sign == 1)? res : -res;
    }
}