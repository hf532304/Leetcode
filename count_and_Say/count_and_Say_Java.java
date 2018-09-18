class Solution {
    public String countAndSay(int n) {
        String res = "1";          //the initial state
        String tmp = "";
        String tmp1 = "";
        int Index = 1;                  //index of String
        int count = 1;
        String[][] dp = new String[11][11];        // dynamic programming,first index for number, second index for times
        for(int i = 1; i < 11; i++){
            for(int j = 1; j < 11; j++){
                dp[i][j] = "";
                dp[i][j] += (char)(j+'0');
                dp[i][j] += (char)(i+'0');
            }
        }
        for(int i = 0; i < n-1; i++){
            while(Index <= res.length()){
                if(Index < res.length() && (res.charAt(Index) == res.charAt(Index - 1)))
                    count++;
                else{
                    if(dp[res.charAt(Index-1)-'0'][count] != null){
                        tmp += dp[res.charAt(Index-1)-'0'][count];
                    }
                    else{
                        tmp1 += (char)(count + '0');
                        tmp1 += res.charAt(Index - 1);
                        tmp += tmp1;
                        dp[res.charAt(Index-1)-'0'][count] = new String(tmp1);     
                    }
                    count = 1;
                    tmp1 = "";
                }
                Index++;
            }
            res = new String(tmp);
            tmp = "";
            Index = 1;
        }
        return res;
    }
}