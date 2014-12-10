class Solution {
public:
    void dfs(TreeNode *root,int &max,int depth){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL ){
            if(depth > max)
                max = depth;
            return;
        }
        
        dfs(root->left,max,depth+1);
        dfs(root->right,max,depth+1);
        
    }


    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        int max = INT_MIN;
        
        dfs(root,max,1);
        return max;
    }
};