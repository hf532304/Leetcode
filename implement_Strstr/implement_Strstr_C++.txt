class Solution {
public:
    int strStr(string haystack, string needle) {   //KMP algorithm
        vector<int> Table(needle.length(),0);
        int h_Index = 0;
        if(haystack.length() < needle.length())
            return -1;
        if(needle.length() == 0)
            return 0;
        for(int i = 1, len = 0;i < needle.length();){             //get the table,len mean current maxlen
            if(needle[i] == needle[len])
                Table[i++] = ++len;                                //match
            else if(len != 0)
                len = Table[len-1];                               //this step is important: according to the symmetry of the len, i-- to 
            else                                                  //i-Table[len-1] is equal to Table[len-1], which is longest symmetry string
                Table[i++] = 0;
        }
         while(h_Index <= haystack.length() - needle.length()){
             int n_Index = 0;
             while(n_Index < needle.length()){
                 if(needle[n_Index] == haystack[h_Index + n_Index]){
                     n_Index++;
                 }
                 else{
                     break;
                 }
                 if(n_Index == needle.length()){
                     return h_Index;
                 }
             }
             if(n_Index == 0){                   //no match 
                 h_Index ++;
             }
             else{
                 if(Table[n_Index-1] == 0){
                     h_Index++;
                 }
                 else{
                     h_Index += n_Index - Table[n_Index-1];
                 }
             }
         }        
        return -1;
    }
};