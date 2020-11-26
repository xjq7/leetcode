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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        int len=0;
        stack<ListNode*> s;
        ListNode* n=head;
        while(n){
            s.push(n);
            n=n->next;
            len++;
        }
        k%=len;
        n=head;
        while(k--){
            ListNode* cur=s.top();s.pop();
            cur->next=n;
            n=cur;
        }
        ListNode* rear=s.top();
        rear->next=nullptr;
        return n;
    }   
};