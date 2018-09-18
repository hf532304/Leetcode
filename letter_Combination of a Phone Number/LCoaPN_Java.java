class Solution {
    public List<String> letterCombinations(String digits) {
        char map[][] = new char[8][4];
        char N = 0;
        for(int i = 0; i < 5; i++){
            map[i] = new char[]{(char)('a'+ 3*i), (char)('b' + 3*i), (char)('c' +3*i),N};
        }
        map[5] = new char[]{'p','q','r','s'};
        map[6] = new char[]{'t','u','v',N};
        map[7] = new char[]{'w','x','y','z'};                     //map table
        List<String> res = new ArrayList<String>();
        if(digits.length() == 0)                                 //when input is nothing
            return res;
        res.add("");                                            //to begin the loop
        int index = 0;
        while(index < digits.length()){
            int Size = res.size();                  //size would change by adding
            for(int i = 0; i < Size; i++){
                for(int tmp = 0; tmp < 4; tmp++){
                    char added = map[digits.charAt(index) - '2'][tmp];
                    if(added == 0)
                        break;
                    String s = res.get(0);              //have get the former one
                    s += added;
                    res.add(s);
                }
                    res.remove(0);
            }
            index++;
        }
        return res;
    }
}