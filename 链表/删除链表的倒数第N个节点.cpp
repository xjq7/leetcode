/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//  快慢指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=nullptr,*fast=head;
        while(fast){
            fast=fast->next;
            if(n>0){
                n--;
            }else{
                if(slow==nullptr){
                    slow=head;
                }else{
                    slow=slow->next;
                }
            }
        }
        if(slow==nullptr){
            head=head->next;
        }else{
            slow->next=slow->next->next;
        }
        return head;
    }
};