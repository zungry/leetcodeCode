class Solution {
public:
    
    bool isLeftRight(TreeNode *left,TreeNode *right){
        if (left == NULL && right == NULL) {
            return true;
        };
        
        if (left == NULL || right == NULL) {
            return false;
        }
        
        return left->val == right->val && isLeftRight(left->left, right->right) && isLeftRight(left->right, right->left);
    }
    
    
    
    
    
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        
        return isLeftRight(root->left, root->right);
    }
};