class Solution {
public:
    struct cmp{
        bool operator ()(const ListNode *a,const ListNode *b){
            return a->val > b->val;    
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(lists.size()==0){
            return NULL;
        }
        
        priority_queue<ListNode *,vector<ListNode*>,cmp> heap1;

        ListNode node(0);
        ListNode *ret = &node;


        for(int i = 0;i < n;i++){
            if(lists[i])
                heap1.push(lists[i]);
        }

        while(!heap1.empty()){
            ListNode *p = heap1.top();
            heap1.pop();

            ret->next = p;
            ret = p;

            if(p->next)
                heap1.push(p->next);
        }
        return node.next;
    } 
};
