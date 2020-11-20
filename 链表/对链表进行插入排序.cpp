// 原链表上操作
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode* h=new ListNode(0,head);
        while(head->next){
            ListNode* hHead = h;
            bool hasOperator=false;
            while(h->next!=head->next){
                if(h->next->val>head->next->val){
                    hasOperator=true;
                    ListNode* temp = head->next;
                    head->next=head->next->next;
                    temp->next=h->next;
                    h->next=temp;
                    break;
                }else{
                    h=h->next;
                }
            }
            if(!hasOperator)head=head->next;
            h=hHead;
        }      
        head=h->next;  
        delete h;
        return head;
    }
};

// 申请新的空间
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode* h=new ListNode(0,head);
        h->next=new ListNode(head->val,NULL);
        while(head->next){
            ListNode* hHead = h;
            while(h->next!=NULL){
                if(h->next->val>head->next->val){
                    h->next= new ListNode(head->next->val,h->next);
                    break;
                }else{
                    h=h->next;
                }
            }
            if(!h->next)h->next=new ListNode(head->next->val,NULL);
            head=head->next;
            h=hHead;
        }        
        return h->next;
    }
};