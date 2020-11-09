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
    ListNode* middleNode(ListNode* head) {
        ListNode* p=head;
        int n=0;
        while(p){
            n++;
            p=p->next;
        }
        int middle = n/2;
        while(middle--){
            head=head->next;
        }
        
        return head;
    }
};