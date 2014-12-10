class Solution {
public:
    bool isValid(TreeNode *root, int maxVal, int minVal, bool checkMax, bool checkMin) {
        if(NULL == root) return true;
        if(checkMax && root->val >= maxVal) return false;
        if(checkMin && root->val <= minVal) return false;
        bool leftValid = isValid(root->left, root->val, minVal, true, checkMin);
        if(!leftValid) return false;
        return isValid(root->right, maxVal, root->val, checkMax, true);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValid(root,0,0,false,false);
    }
};