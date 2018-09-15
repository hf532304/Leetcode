class Solution {
public:
    bool isValid(string s) {          //use stack
        stack<char> S;
        if(s.length() == 0)
            return true;
        int index_S = 0;
        while(index_S < s.length()){
            if(s[index_S] == '(' || s[index_S] == '[' || s[index_S] == '{'){
                S.push(s[index_S]);
            }
            else{
                if(S.empty()) return false;
                char tmp = S.top();
                if((s[index_S] == ')' && tmp == '(') || (s[index_S] == ']' && tmp == '[')
                   || (s[index_S] == '}' && tmp == '{')){
                    S.pop();
                }
                else
                    return false;
            }
            index_S ++;
        }
        if(S.empty()) return true;
        else return false;
    }
};