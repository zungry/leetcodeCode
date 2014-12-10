class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return NULL;

        int depth = INT_MAX;
        int curDepth = 0;

        dfs(root,depth,curDepth);
        
        return depth;

    }


    void dfs(TreeNode *root,int &depth,int curDepth){
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL && curDepth + 1 < depth){
            depth = curDepth + 1;
        }
        
        
        dfs(root->left,depth,curDepth+1);
        dfs(root->right,depth,curDepth+1);
    };
};