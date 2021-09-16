ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* front=head;
        for(int i=0;i<n;i++){
            if(front==NULL) return NULL;
            front=front->next;

        }
        if(front==NULL){
         head=head->next;
         return head;
        }
        while(front->next!=NULL){
            curr=curr->next;
            front=front->next;
        }
        curr->next=curr->next->next;
        return head;
    }
