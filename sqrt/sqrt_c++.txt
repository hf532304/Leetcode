class Solution {
public:
    int mySqrt(int x) {
        int digit = 0;        //count for digits of x
        int res = 0;
        int div = 1;
        if(x == 0) return 0;
        int tmp = x;
        while(tmp != 0){
            tmp = tmp/10;
            digit++;
        }
        digit /= 2;
        while(digit > 1){
            div *= 10;
            digit = digit-1;
        }
        res = div;
        while(x / res >= res){
            res++;
        }
        return --res;
    }
};