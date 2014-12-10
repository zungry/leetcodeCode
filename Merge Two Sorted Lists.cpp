class Solution {
    
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l1_tmp;
        ListNode *l2_tmp;
        ListNode *pre = l1;
        ListNode *old = l1;
        if(l1 == NULL && l2 == NULL) return NULL;
        //if(l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        while (l1!= NULL&& l2!=NULL) {
            
            if (l1->val < l2->val) {
                pre = l1;
                l1 = l1->next;
            }
            else{
                if(pre == l1){
                    l2_tmp = l2->next;
                    l2->next = l1;
                    pre = l2;
                    old = pre;
                    l2 = l2_tmp;
                    
                }
                else{
                    l2_tmp = l2->next;
                    pre->next = l2;
                    l2->next = l1;
                    pre = l2;
                    l2 = l2_tmp;
                }
            }
        }
        
        if (l2 != NULL) {
            pre->next = l2;
        }
        return old;
    }
};