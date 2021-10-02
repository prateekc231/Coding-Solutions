ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* head_odd = NULL;
        ListNode* tail_odd = NULL;
        ListNode* head_even = NULL;
        ListNode* tail_even = NULL;
        ListNode* temp = head;
        bool isodd = true;
        while(temp!= NULL){
            if(isodd){
                if(head_odd == NULL){
                    head_odd = tail_odd = temp;
                    temp=temp->next;
                    head_odd->next = NULL;
                }else{
                    tail_odd->next = temp;
                    tail_odd = temp;
                    temp = temp->next;
                    tail_odd->next = NULL;
                }
                isodd= !isodd;
            }
            else{
                if(head_even == NULL){
                    head_even = tail_even = temp;
                    temp=temp->next;
                    head_even->next = NULL;
                }else{
                    tail_even->next = temp;
                    tail_even = temp;
                    temp = temp->next;
                    tail_even->next = NULL;
                }
                isodd= !isodd;
            }
        }
        tail_odd->next = head_even;
        return head_odd;

    }
