class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int maxlen = 0;
        int start = 0;
        unordered_map<char,int> Hashmap;
        int len = 0;
        int j = 0;
        unordered_map<char,int>::iterator repeat;
        while(j < s.length()){
            repeat = Hashmap.find(s[j]);
            if(repeat != Hashmap.end()){
                start = max(start,Hashmap.at(s[j]) + 1);
            }
            Hashmap[s[j]] = j;
            maxlen = max(maxlen,j - start + 1);
            j++;
         }
        return maxlen;        
    }
};