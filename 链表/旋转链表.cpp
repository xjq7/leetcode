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

//  利用栈
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

// 先连接成环,然后在适当的地方解环
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
        ListNode* n=head;
        int len=1;
        while(true){
            if(n->next==nullptr){
                n->next=head;
                break;
            }
            len++;
            n=n->next;
        }
        n=head;
        k%=len;k=len-k;
        ListNode* pre=n;
        while(k--){
            pre=n;
            n=n->next;
        }
        pre->next=nullptr;
        return n;
    }   
};