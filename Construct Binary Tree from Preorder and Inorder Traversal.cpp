class Solution {
public:
    TreeNode *bulid(vector<int> &preorder,vector<int> &inorder,int pl,int pr,int il,int ir){
        TreeNode *root;
        if (pl > pr || il > ir) {
            root =NULL;
        }else{
            root = new TreeNode(preorder[pl]);
            int i;
            
            for (i = il; i < ir && preorder[pl] != inorder[i]; i++);
            root->left = bulid(preorder, inorder, pl+1, pl+i-il, il, i-1);
            root->right = bulid(preorder, inorder, pl+i-il+1, pr, i+1, ir);
        }
        return root;
    }
    
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return bulid(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
