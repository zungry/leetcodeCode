class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        if(root == NULL)
            return vector<vector<int> >();

        vector<vector<int> > ret;
        
        bfs(root,ret,0);
        return ret; 
    }

    void bfs(TreeNode *root,vector<vector<int> > &ret,int depth){
        if(root == NULL)
            return ;
         
        if(ret.size() > depth){
            ret[depth].push_back(root->val);
        }
        else{
            vector<int> a;
            a.push_back(root->val);
            ret.push_back(a);
        }
        bfs(root->left,ret,depth+1);
        bfs(root->right,ret,depth+1);
    }       
};