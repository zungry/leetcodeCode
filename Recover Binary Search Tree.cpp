class Solution {
    
private:
    TreeNode *mis1,*mis2;
    TreeNode *pre;
    
public:
    
    void recursive_tree(TreeNode *root){
        if (root == NULL) {
            return;
        }
        
        if (root->left != NULL) {
            recursive_tree(root->left);
        }
        
        if (pre != NULL && root->val < pre->val) {
            if (mis1 == NULL) {
                mis1 = pre;
                mis2 =root;
            }else{
                mis2 = root;
            }
        }
        
        pre = root;
        if (root->right != NULL) {
            recursive_tree(root->right);
        }
    }
    
    
    
    void recoverTree(TreeNode *root) {
        recursive_tree(root);
        if (mis1 != NULL && mis2 !=NULL) {
            std::swap(mis1->val,mis2->val);
        }
    }
};
