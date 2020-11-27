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
    void reorderList(ListNode* head) {
        ListNode* n=head;
        stack<ListNode*> s;
        int len=0;
        while(n){
            len++;
            s.push(n);
            n=n->next;
        }
        if(len<3)return;
        int l=len/2;
        int k=l*2+1==len?l:l-1;
        cout<<k;
        while(k--){
            ListNode* cur=s.top();s.pop();
            s.top()->next=nullptr;
            cur->next=head->next;
            head->next=cur;
            head=cur->next;

        }        
    }
};