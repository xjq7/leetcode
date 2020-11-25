/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  双端队列
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        deque<ListNode*> dq;
        ListNode* h=head;
        int i=n-m+1;
        int j=1;
        while(h){
            if(i&&j>=m){
                dq.push_back(h);
                i--;
            }
            j++;
            h=h->next;
        }
        while(dq.size()>1){
            int temp;
            ListNode* pre=dq.front();dq.pop_front();
            ListNode* rear=dq.back();dq.pop_back();
            cout<< pre->val<<rear->val;
            temp=pre->val;
            pre->val=rear->val;
            rear->val=temp;
        }
        return head;
    }
};