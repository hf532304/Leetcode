class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List> Hash = new HashMap<String, List>();    //use the hashmap to store the list
        if (strs.length == 0) return new ArrayList();
        int[] count = new int[26];
        for(String each : strs){
            Arrays.fill(count,0);
            for(char c : each.toCharArray()){
                count[c-'a'] += 1;
            }
            StringBuilder newStr = new StringBuilder("");
            for(int i = 0; i < 26; i++){
                newStr.append("#");
                newStr.append(count[i]);
            }
            String newS = newStr.toString();
            if(!Hash.containsKey(newS)){
                Hash.put(newS, new ArrayList());
            }
                Hash.get(newS).add(each);
        }
        return new ArrayList(Hash.values());
    }
}