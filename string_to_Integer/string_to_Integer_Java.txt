class Solution {
    public int myAtoi(String str) {
        int i = 0;
        int sign = 1;
        int res = 0;
        int size = str.length();
        while(size > i &&str.charAt(i) == ' '){i++;}                   //ignore the whitespace
        if(size > i && str.charAt(i) == '-') {sign = -1;i++;}               //judge only one bit for signal
        else if (size > i && str.charAt(i) == '+') {i++;}
        while(size > i && str.charAt(i) <= '9' && str.charAt(i) >= '0'){   //judge only number
            if(sign > 0 && (Integer.MAX_VALUE / 10.0 < res || Integer.MAX_VALUE - 10 * res < (str.charAt(i) - '0')))
                return Integer.MAX_VALUE;
            else if (sign < 0 &&(Integer.MIN_VALUE / 10.0 > res || Integer.MIN_VALUE - 10 * res > -(str.charAt(i) - '0')))
                return Integer.MIN_VALUE;
            res = res * 10 + (sign * (str.charAt(i) - '0'));
            i++;
        }
        return res;
    }
}