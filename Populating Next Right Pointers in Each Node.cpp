class Solution{
public:
    void connect(TreeLinkNode *root){
        if (root == NULL) {
            return;
        }
    
        queue<TreeLinkNode *> Q;
        
        Q.push(root);
        
        
        int row = 1;
        int count = 0;
        
        while (!Q.empty()) {
            TreeLinkNode *tmp = Q.front();
            Q.pop();
            count++;
            
            if (tmp->left) {
                Q.push(tmp->left);
            }
            
            if (tmp->right) {
                Q.push(tmp->right);
            }
            
            if (count == row) {
                tmp->next = NULL;
                count = 0;
                row *= 2;
            }else{
                tmp->next = Q.front();
            }
            
        }
        
    }
};

