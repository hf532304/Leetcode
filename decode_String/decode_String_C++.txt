class Solution {
public:
    string decodeString(string s) {
        stack<int> S;             // a stack to match the pairs
        vector<char> Tmp;              // for temporary saving string
        int i = 0;
        int num = 0;                   // times for loop
        int times = 0;
        while(s[i] != NULL){            //until the end
            if(s[i] <= '9' && s[i] >= '0'){     
                num = num * 10 + s[i] - '0';
            }
            else if(s[i] == '['){
                S.push(-num);
                num = 0;
            }
            else if(s[i] == ']'){
                while(S.top() > 0){
                    Tmp.insert(Tmp.begin(),S.top());
                    S.pop();
                }
                times = -S.top();
                S.pop();
                for(int i = 0; i < times; i++){
                    for(auto j : Tmp){
                        S.push(j); 
                    }
                }
                Tmp.clear();
            }
            else{
                S.push(s[i]);
            }
            i++;
        }
        while(!S.empty()){
            Tmp.insert(Tmp.begin(), S.top());
            S.pop();
        }
        string res(Tmp.begin(), Tmp.end());
        return res;
    }
};