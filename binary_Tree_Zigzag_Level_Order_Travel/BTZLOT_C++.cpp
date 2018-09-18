/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Travel_Tree(TreeNode* cur, vector<vector<int>>& res, int level){
        if(cur == NULL)
            return;
        if(res.size() <= level){
            vector<int> one_layer;
            res.push_back(one_layer);
        }
        vector<int> *one_layer = &(res.at(level));
        if(level % 2 == 0){
            one_layer->push_back(cur->val);
        }
        else{
            one_layer->insert(one_layer->begin(),cur->val);
        }
        Travel_Tree(cur->left, res, level + 1);
        Travel_Tree(cur->right, res, level + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {     //to implement zigzag, we need a stack and a vector
        vector<vector<int>> res;
        Travel_Tree(root, res, 0);
        return res;
    }
};