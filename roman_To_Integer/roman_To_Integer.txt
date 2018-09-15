class Solution {
    public int romanToInt(String s) {
        int res = 0;
        int roman[] = new int[100];
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        int s_len = s.length();
        int i = 0;
        while(i < s_len){
            res += roman[s.charAt(i)];
            if(i > 0 && roman[s.charAt(i)] > roman[s.charAt(i-1)]){
                res -= 2 * roman[s.charAt(i-1)];
            }
            i++;
        }
        return res;
    }
}