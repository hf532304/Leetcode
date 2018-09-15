class Solution {
public:
	bool isMatch(string s, string p) {    
        int s_len = s.size();
        int p_len = p.size();
		if(p.empty() == true){
            return s.empty();
        }
        bool theFirst = (s.empty() != true && ((s[0] == p[0]) || (p[0] == '.')));   //judge the first character
        if(p_len > 1 && p[1] == '*'){
            return ((theFirst && isMatch(s.substr(1,s_len - 1),p))||isMatch(s,p.substr(2,p_len - 2)));    //if * is the next one
        }
        else{
            return (theFirst && isMatch(s.substr(1,s_len - 1),p.substr(1,p_len - 1)));
        }
	}
};