class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n < 0 || head == NULL)
            return NULL;

        if(n == 0){
            if(head->next == NULL)
                return NULL;
            else 
                return head->next;
        }


        ListNode *current = head;
        ListNode *nthnode = head;
        for(int i = 0;i < n;i++){
            nthnode = nthnode->next;
        }
        
        if(nthnode == NULL)
            return head->next;

        


        while(nthnode->next){
            nthnode = nthnode->next;
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};