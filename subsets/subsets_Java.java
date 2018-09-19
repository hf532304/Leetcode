class Solution {
    public void dfs(int[] nums, List<Integer> cur, List<List<Integer>> res, int pos){
        List<Integer> tmp = new ArrayList<Integer>(cur);
        res.add(tmp);
        for(int i = pos; i < nums.length; i++){
            cur.add(nums[i]);
            dfs(nums, cur, res, i + 1);
            cur.remove(cur.size() - 1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {// dfs
        List<Integer> cur = new ArrayList<Integer>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        dfs(nums, cur, res, 0);
        return res;
    }
}