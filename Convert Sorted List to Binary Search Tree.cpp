class Solution {
public:
    int getLengh(ListNode *root){
        if (root == NULL)
            return 0;
        int len = 1;
        while(root->next){
            len++;
            root = root->next;
        }
        return len;
    }


    TreeNode *makeTree(ListNode *node,int left,int right){
        if(left > right)
            return NULL;

        int mid = (right - left )/2 + left;

        ListNode *p = node;

        for(int i = left; i < mid; i++)
            p = p->next;

        TreeNode *leftNode = makeTree(node,left,mid-1);
        TreeNode *rightNode = makeTree(p->next,mid+1,right);
        
        TreeNode *tNode = new TreeNode(p->val);

        tNode->left = leftNode;
        tNode->right = rightNode;

        return tNode;
    }



    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL)
            return NULL;

        int len = getLengh(head);
        
        TreeNode *root = makeTree(head,0,len-1);
        return root;
    }
};