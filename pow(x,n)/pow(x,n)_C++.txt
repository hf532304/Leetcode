class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        if(N == 0) return 1;
        double mul = x;
        for(long long i = N; i > 0; i /= 2){
            if(i%2 == 1){                 //when encounter 1
                res = res * mul;
            }
                mul =  mul * mul;
        }
        return res;
    }
};