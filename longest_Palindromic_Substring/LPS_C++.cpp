class Solution {
public:
 bool IsPalindrome(string s, int Begin, int End){
     while(Begin < End){                          //two pointers to go throuth the string
         if(s[Begin] != s[End]) return false;
         else{
             Begin++;
             End--;
         }
     }
     return true;
    }
 string longestPalindrome(const string s) {
        vector<int> Table[256]; 
        int MaxLength = 1;
        int Max_S = 0;
        int Max_E = 0;
        for(int i = 0; i < s.length(); i++){
            Table[s[i]].push_back(i);                   // record the index of each char
        }
        for(int i = 0; i < 256; i++){
            if(Table[i].size() < 2)                     // find the start and end of a palindrome string
                continue;
            else{
                for(int l = 0; l < Table[i].size() - 1; l++){
                    int start = Table[i][l];
                    for(int r = Table[i].size() - 1; r > l; r--){
                        int end = Table[i][r];
                        if(IsPalindrome(s,start,end) && MaxLength < (end- start + 1)){
                            MaxLength = end - start + 1;
                            Max_S = start;
                            Max_E = end;
                            break;
                        }                
                    }
                }
            }
        }
     return s.substr(Max_S, MaxLength);
    }
};