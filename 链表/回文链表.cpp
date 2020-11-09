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
    bool isPalindrome(ListNode* head) {
        ListNode* p=head;
        int n=0;
        while(p){
            n++;
            p=p->next;
        }
        stack<int> s1;
        int middle = n/2;
        while(middle--){
            s1.push(head->val);
            head=head->next;
        }
        if(n%2){
            head=head->next;
        }
        while(s1.size()){
            if(s1.top()!=head->val){
                return false;
            }
            s1.pop();
            head=head->next;
        }
        return true;
    }
};