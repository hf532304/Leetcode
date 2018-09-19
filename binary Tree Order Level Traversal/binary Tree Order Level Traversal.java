/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> sub_Res = new ArrayList<Integer>();
        if(root == null)    return res;
        q.offer(root);
        while(!q.isEmpty()){
            int size = q.size();         //current level number
            while(size > 0){
                TreeNode cur = q.peek();
                sub_Res.add(cur.val);
                q.poll();
                if(cur.left != null) q.offer(cur.left);
                if(cur.right != null) q.offer(cur.right);
                size--;
            }
            res.add(new ArrayList<Integer>(sub_Res));
            sub_Res.clear();
        }
        return res;
    }
}