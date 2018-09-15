class Solution {
    public String addBinary(String a, String b) {
        int a_Len = a.length();
        int b_Len = b.length();
        int[] res = new int[a_Len + 1]a;
        StringBuilder R = new StringBuilder("");
        boolean flag = false;
        for(int r : res){
            r = 0;
        }
        if(a_Len < b_Len)
            return addBinary(b,a);          //to make sure a_Len >= b_Len
        for(int i = a_Len - 1; i >= 0; i--){
            res[i + 1] += ((a.charAt(i) - '0') + (((i > (a_Len - b_Len -1)) ? b.charAt(i-(a_Len - b_Len)) : '0') - '0'))%2;
            res[i] += ((a.charAt(i) - '0') + (((i > (a_Len - b_Len -1)) ? b.charAt(i-(a_Len - b_Len)) : '0') - '0'))/2;
            res[i] += res[i+1]/2;                  // carry
            res[i+1] %=2;
        }
        for(int i = 0 ; i < a_Len+1; i++){
            if(i < a_Len && res[i] == 0 && !flag){
                continue;               
            }
            flag = true;
            R.append((char)(res[i] + '0'));
        }
        return R.toString();
    }
}