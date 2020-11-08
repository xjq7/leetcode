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
    int getDecimalValue(ListNode* head) {
        ListNode* p=head;
        int n=0;
        while(p){
            n++;
            p=p->next;
        }
        int count =0;
        while(head){
            count +=head->val*pow(2,n-1);
            n--;
            head=head->next;
        }
        return count;
    }
};