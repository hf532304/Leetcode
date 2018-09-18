class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        int maxlen = 0;
        HashMap<Character, Integer> hashmap = new HashMap<>();
        int j = 0;
        int i = 0;
        while(j < s.length()){
            if(hashmap.containsKey(s.charAt(j)) != false){
				while(hashmap.containsKey(s.charAt(j)))
                    hashmap.remove(s.charAt(i++));
            }
            hashmap.put(s.charAt(j), j);
			res = hashmap.size();
            maxlen = Math.max(maxlen,res);
            j++;
         }
        return maxlen;    
    }
}