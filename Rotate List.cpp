class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        int len = 0;
        ListNode *ptr = head;
        ListNode *tail = head;
        
        while (ptr != NULL) {
            len++;
            tail = ptr;
            ptr = ptr->next;
        }
        
        k = k % len;
        
        ptr = head;
        for (int i=0; i<len - k - 1; i++) {
            ptr = ptr->next;
        }
        
        tail->next=head;
        head = ptr->next;
        ptr->next = NULL;
        
        return head;
    }
};
