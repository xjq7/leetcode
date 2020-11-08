/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* p = head;
        ListNode* pred = NULL;
        while(p->val!=val){
            pred=p;
            p=p->next;
        }
        if(pred==NULL){
            head=head->next;
        }else{
            pred->next=p->next;
        }
        return head;
    }
};