class Solution{
public:
    void dfs(int &sum,TreeNode *root,int headtoleaf){
        if(root == NULL) return;
        headtoleaf = headtoleaf*10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum += headtoleaf;
            return;
        } 


        dfs(sum,root->left,headtoleaf);
        dfs(sum,root->right,headtoleaf);
    } 


    int sumNumbers(TreeNode *root){
        if(root == NULL)
          return 0;
        int sum = 0;
        int headtoleaf = 0;
        dfs(sum,root,headtoleaf);                                                                                                                                                                            
        return sum;
    }          


};