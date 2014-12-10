class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
            
        help(ret,root);
        return ret;
    }
    
    void help(vector<int> &ret,TreeNode *root){
        if(root->left)
            help(ret,root->left);
        ret.push_back(root->val);
        if(root->right)
            help(ret,root->right);
    }
};