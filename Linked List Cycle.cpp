class Solution {
public:
     bool hasCycle(ListNode *head) {
        ListNode *first = head;
        if (head == NULL) {
            return false;
        }
        if (head->next == NULL) {
            return false;
        }
        ListNode *second = first->next;
        while (second!=NULL && first!=second) {
            first = first->next;
            if(first == NULL)
                return false;
            second = second->next;
            if(second == NULL)
            return false;
            second = second->next;
        }
        if(first == second){
            return true;
        }
        return false;
    }
};