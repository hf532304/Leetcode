class Solution {
    public int strStr(String haystack, String needle) {
        int res = -1;
        if(needle.length() == 0)          //if needle is empty
            return 0;
        int i = 0;                        //pointer for haystack
        while(i < haystack.length()){
            int j = 0;                     //pointer for needle
            int i_tmp = i;
            while(true){
                if(haystack.charAt(i_tmp) != needle.charAt(j)){
                    break;
                }
                else{
                    i_tmp++;
                    j++;
                }
                if(j == needle.length())
                    return i;
                if(i_tmp == haystack.length())
                    return -1;
            }
            i++;
        }
        return res;
    }
}