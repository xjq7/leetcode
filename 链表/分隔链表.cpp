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
    ListNode* partition(ListNode* head, int x) {
        ListNode* r1=new ListNode();
        ListNode* r2=new ListNode();
        ListNode* r11=r1;
        ListNode* r22=r2;
        while(head){
            if(head->val<x){
                r11->next=new ListNode(head->val);
                r11=r11->next;
            }else{
                r22->next=new ListNode(head->val);
                r22=r22->next;
            }
            head=head->next;
        }
        r11->next=r2->next;
        return r1->next;
    }
};


// 
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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1,v2;
        ListNode* n=head;
        while(n){
            if(n->val<x){
                v1.push_back(n->val);
            }else{
                v2.push_back(n->val);
            }
            n=n->next;
        }
        ListNode* t=new ListNode();
        ListNode* ret=t;
        for(auto v:v1){
            ListNode* temp=new ListNode(v);
            t->next=temp;
            t=temp;
        }
        for(auto v:v2){
            ListNode* temp=new ListNode(v);
            t->next=temp;
            t=temp;
        }
        return ret->next;
    }
};