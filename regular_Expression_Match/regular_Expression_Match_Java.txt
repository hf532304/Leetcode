class Solution {
    boolean memo[][];
    public boolean isMatch(String s, String p) {
        memo = new boolean[s.length() + 1][p.length() + 1];
        memo[s.length()][p.length()] = true;
        for(int i = s.length(); i >= 0 ; i--){
            for(int j = p.length() -1; j >= 0; j--){
                boolean first_Match = (i < s.length()&&((s.charAt(i) == p.charAt(j))||(p.charAt(j) == '.')));
                if(j + 1 < p.length() && p.charAt(j + 1) == '*'){
                         memo[i][j] = memo[i][j+2] || (first_Match && memo[i+1][j]);
                }
                else{
                    memo[i][j] = (first_Match && memo[i+1][j+1]);
                }
            }
        }
        return memo[0][0];
    }
}