class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
            
        ListNode* pre = head;
        ListNode* current;
        if(head->next)
            current = head->next;
        else
            return head;
        
        while(current){
            if(current->val == pre->val){
                if(current->next == NULL){
                    pre->next = NULL;
                    break;
                }else{
                    pre->next = current->next;
                    current = current->next;
                }
            }else{
                pre = current;
                current = current->next;
            }
        }
        return head;
    }
};