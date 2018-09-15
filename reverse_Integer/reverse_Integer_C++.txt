class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        int res = 0;
        if(x < 0)
            sign = -1;
        while(x != 0){
            if(sign > 0 &&(INT_MAX / 10 < res || INT_MAX - 10 * res < x % 10))
                return 0;
            if(sign < 0 &&(INT_MIN / 10 > res || INT_MIN - 10 * res > x % 10))
                return 0;
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return res;
    }
};