class Solution {
public:
    TreeNode *build(vector<int> &num,int l ,int r){
        TreeNode *root;
        if (l > r) {
            root = NULL;
            return root;
        }else{
            int mid = (l + r)/2;
            root = new TreeNode(num[mid]);
            
            root->left = build(num, l, mid - 1);
            root->right = build(num, mid+1, r);
        }
        return root;
    }
    
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
      return  build(num, 0, num.size()-1);
    }
    
    
};
