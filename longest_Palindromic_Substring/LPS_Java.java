class Solution {
    public String longestPalindrome(String s) {       //center expand
        int MaxLength = 1;
        int Length = 1;
        int Begin = 0 ;
        int End = -1;
        if(s.length() > 0)
            End = 0;
        for(int i = 1; i < s.length(); i++){
            int tmp = 1;
            Length = 1;
            while(i >= tmp && tmp < s.length() - i && s.charAt(i-tmp) == s.charAt(i+tmp)){
                Length += 2;
                tmp ++;
            }
            if(Length > MaxLength){
                MaxLength = Length;
                Begin = i - tmp + 1;
                End = i + tmp - 1;
            }
            tmp = 1;
            if(s.charAt(i) == s.charAt(i-1))
            {
                Length = 2;
              while(i >= tmp + 1 && tmp < s.length() - i && s.charAt(i - 1 - tmp) == s.charAt(i + tmp)){
                    Length += 2;
                    tmp ++;               
                  }
                if(Length > MaxLength){
                 MaxLength = Length;
                 Begin = i - tmp ;
                  End = i + tmp -1 ;
                }
            }
        }
        return s.substring(Begin, End + 1);
        
    }
}