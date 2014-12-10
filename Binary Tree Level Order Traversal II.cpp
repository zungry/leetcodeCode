class Solution {
public:

    vector<vector<int> >ret;

    void levelTra(TreeNode *root, int level){
        if(root == NULL)
           return;
        
        if(level == ret.size()){
            vector<int> v;
            ret.push_back(v);
        }

        ret[level].push_back(root->val);
        levelTra(root->left,level+1);
        levelTra(root->right,level+1);

    }

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        levelTra(root,0);
        return vector<vector<int> >(ret.rbegin(),ret.rend());
    }
};