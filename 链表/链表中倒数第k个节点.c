struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(k<1)return NULL;
    if(!head)return NULL;
    struct ListNode* p = head;
    struct ListNode* p1 = head;
    int j=0;
    while(j<k){
        p = p->next;
        j++;
    }
    if(!p&&j>k)return NULL;
    while(p){
        p = p->next;
        p1 = p1->next;
    }
    return p1;
}