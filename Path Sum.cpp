class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, sum, 0);
    };
private:
    bool dfs(TreeNode *node,int sum ,int cursum){
        
        if (node == NULL) {
            return false;
        }
        
        if (node->left == NULL && node->right == NULL) {
            return node->val+cursum == sum;
        }
        
        return dfs(node->left, sum, cursum+node->val)||dfs(node->right, sum, cursum+node->val);
        
    };
};