class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> Judge;
        vector<vector<string>> Res;
        int Index;
        bool flag_Equal = true;
        if(strs.size() == 0) return Res;
        while(strs.size() > 0){
            string Tmp = strs[0];
            strs.erase(strs.begin());
            vector<int> Record(26,0);
            for(int i = 0; i < Tmp.length(); i++){
                Record[Tmp[i] - 'a'] += 1;
            }                                                //count for times of char   
            for(Index = 0; Index < Judge.size(); Index++){        //judge if it is anagram
                if(Tmp.length() != Res[Index][0].length()) continue;           //if length is not match, jump over
                vector<int> Exist = Judge[Index];
                for(int i = 0; i < 26; i++){
                    if(Exist[i] != Record[i]){
                        flag_Equal = false;
                    }
                }
                if(flag_Equal){
                    Res[Index].push_back(Tmp);
                    break;
                }
                else{
                    flag_Equal = true;
                    continue;
                }
            }
            if(Index == Judge.size()){                          //no match
                Judge.push_back(Record);
                vector<string> New;
                New.push_back(Tmp);
                Res.push_back(New);
            }
        }
        return Res;
    }
};