class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        
        if (head->next == NULL) {
            return NULL;
        }
        
        if(head->next->next == NULL)
            return NULL;
        
        ListNode *first = head->next;
        ListNode *second = head->next->next;
        
        while (1) {
            if(first == second)
                break;
            first = first->next;
            if(first == NULL)
                return NULL;
            second = second->next;
            if(second == NULL)
                return NULL;
            second = second->next;
            if(second == NULL)
                return NULL;
        }
        
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    };
};