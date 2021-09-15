typedef pair<int,ListNode*> pi;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<pi, vector<pi>,greater<pi>> pq;
        for(int i = 0;i <lists.size(); i++){
            if(lists[i]!=NULL) pq.push(make_pair(lists[i]->val,lists[i]));
        }
        if(pq.size() == 0) return NULL;
        ListNode* head = pq.top().second;
        ListNode* he = pq.top().second;
        pq.pop();
        if(he->next!=NULL){
        pq.push({he->next->val, he->next});}
        ListNode* temp = head;
        while(!pq.empty()){
            temp->next =  pq.top().second;
            he =  pq.top().second;
            pq.pop();
            if(he->next!=NULL){
                pq.push({he->next->val, he->next});
            }
            temp= temp->next;
        }
        temp->next = NULL;
        return head;

    }
};
