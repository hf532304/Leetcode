class Solution {
    vector<string> res;
    char map[8][4] = {{'a', 'b', 'c', 0}, {'d', 'e', 'f', 0}, {'g', 'h', 'i', 0},
           {'j', 'k', 'l', 0}, {'m', 'n', 'o', 0}, {'p', 'q', 'r', 's'},
           {'t', 'u', 'v', 0}, {'w', 'x', 'y', 'z'}};
public:
    vector<string> letterCore(int i_Dig, string digits){
        if(i_Dig == digits.length()){
            return res;
        }
        string tmp = res.back();
        res.pop_back();
        for(int i = 0; i < 4; i++){
            if(map[digits[i_Dig]-'2'][i] == 0)
                break;
            res.push_back(tmp + map[digits[i_Dig]-'2'][i]);
            letterCore(i_Dig+1, digits);
        }
        return res;
    }
    vector<string> letterCombinations(string digits) {     //DFS
        int index_D = 0;                                   //index of digits
        int d_Len = digits.length();
        if(d_Len == 0){                                     //edge case
            return res;
        }
        res.push_back("");
        return letterCore(0,digits);
    } 
};