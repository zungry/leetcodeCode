class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;

        TreeNode *node = root;
        while(node){
            if(node->left){
                TreeNode *pre = node->left;
            while(pre->right)
                pre = pre->right;
            pre->right = node->right;
            node->right = node->left;
            node->left = NULL;
            }
        node = node->right;  
        }    
    }
};