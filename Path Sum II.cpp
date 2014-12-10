class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return  vector<vector<int> >();

        int currentSum = 0;
        vector<vector<int> > ret;
        ret.clear();
        vector<int> path;
        dfs(root,sum,currentSum,ret,path);
        return ret;
    }


    void dfs(TreeNode *root,int sum,int currentSum,vector<vector<int> > &ret,vector<int> path){
        if(root == NULL)
            return ;


        if(root->left == NULL && root->right == NULL && sum == currentSum + root->val){
            path.push_back(root->val);
            ret.push_back(path);
        }
            

        path.push_back(root->val);

        if(root->left){
           dfs(root->left,sum,currentSum+root->val,ret,path);
        }
        if(root->right){
           dfs(root->right,sum,currentSum+root->val,ret,path);
        }
    }
};