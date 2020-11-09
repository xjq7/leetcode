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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast){
            slow=slow->next;
            if(!fast->next){
                return NULL;
            }
            fast=fast->next->next;
            if(slow==fast){
                ListNode* p=head;
                while(slow!=p){
                    slow=slow->next;
                    p=p->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};