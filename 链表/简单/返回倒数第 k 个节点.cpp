// 快慢指针
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(k--){
            fast=fast->next;
        }

        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow->val;
    }
};