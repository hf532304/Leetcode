class Solution {
    public double myPow(double x, int n) {
        int Sign = 1;
        boolean min = false;
        if(n < 0)   Sign = -1;
        if(n == 0)
            return 1;
        if(n == Integer.MIN_VALUE){
            min = true;
            n = n + 1;
        }
        n = Math.abs(n);
        int Bit = 0;
        double Res = 1;
        double[] Count = new double[33];
        Count[0] = 1;
        int num = 1;
        while((Integer.MAX_VALUE>>1) > num && (num<<1) <= n ){          //to get the maximum number no larger than n and is 2's multiply.
            Bit += 1;
            num <<= 1;
        }
        for(int i = 1; i <= Bit + 1; i++){
            if(i == 1){
                Count[i] = x;
                continue;
            }
            Count[i] = Count[i-1] * Count[i-1];
        }
        while(Bit >= 0){
            if(n - num >= 0){
                n -= num;
                Res *= Count[Bit + 1];                
            }
            num >>= 1;
            Bit--;
        }
        if(min) Res *= x;
        return (Sign > 0)? Res : 1/Res;
    }
}