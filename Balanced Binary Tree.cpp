class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool balanced = true;
        help(root,balanced);
        return balanced;
    }

    int help(TreeNode *root,bool &balanced){
        if(!balanced)
            return -1;

        if(root == NULL)
            return 0;

        int lheight = help(root->left,balanced)+1;
        int rheight = help(root->right,balanced)+1;
        if(abs(lheight - rheight) > 1){
            balanced = false;
            return -1;
        }
        return lheight > rheight ? lheight : rheight;

    };
};