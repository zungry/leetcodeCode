class Solution {
public:
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if(root == NULL)
          return ret;
          
        queue<TreeNode *> q;
        vector<int> vec;
        q.push(root);
        int currentLevel = 1;
        int nextLevel = 0; 
        bool left = true;
        
        while(!q.empty()){
        
            TreeNode *cur = q.front();
            q.pop(); 
            currentLevel--;
            vec.push_back(cur->val);
            
            if(cur->left){
                q.push(cur->left);
                nextLevel++;
            }   
            if(cur->right){
                q.push(cur->right);
                nextLevel++;
            }   
            if(currentLevel == 0){
                if(!left){
                    std::reverse(vec.begin(),vec.end());
                }   
                left = !left;
                ret.push_back(vec);
                vec.clear();
                currentLevel = nextLevel;
                nextLevel = 0; 
            }   
            
        }
        return ret;
   }    
}; 
