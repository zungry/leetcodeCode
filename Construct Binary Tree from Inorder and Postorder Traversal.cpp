class Solution {
  
      public:
  
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            int len = postorder.size();
            if(len == 0)  
            return NULL;  
            TreeNode *p = buildhelp(inorder,0,len-1,postorder,0,len-1);  
            return p;  
        }   
  
          TreeNode *buildhelp(vector<int> &inorder,int inleft,int inright,vector<int> &postorder,int poleft,int poright){
              int len = inright - inleft + 1;

             
              
              if(len == 0)
                return NULL;
              
              if(len==1)  {  
                TreeNode *p = new TreeNode(inorder[inleft]);  
                return p;  
              }  
              
              
               int root = postorder[poright];
  
              TreeNode *p = new TreeNode(root);
              int site;
              for(int i = inleft;i <= inright;i++){
                  if(inorder[i] == root){
                      site = i;
                      break;
                  }   
              }   
  
              int left_len = site - inleft;
              int right_len = inright - site;
  
              if(left_len > 0)
                p->left = buildhelp(inorder,inleft,site-1,postorder,poleft,poleft+left_len-1);
              if(right_len > 0)
                p->right = buildhelp(inorder,site+1,inright,postorder,poleft+left_len,poright-1);
  
              return p;                                                                                                                                                                                      
  
          }   
  };
