ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;
        ListNode* temp = head, *new_head = NULL;
        new_head = temp->next;
        temp->next = swapPairs(new_head->next);
        new_head->next = temp;
        return new_head;
    }
