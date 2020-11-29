/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  一次迭代,用一个虚拟头节点可以删除前置节点,用一个状态值记录出现重复的情况,来判断下一次迭代虚拟头节点往后移多少位
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        ListNode* n=new ListNode();
        ListNode* sn=n;
        n->next=head;
        ListNode* cur=head->next;
        bool f=false;
        while(cur){
            while(cur&&cur->val==n->next->val){
                f=true;
                cur=cur->next;
            }
            if(f){
                n->next=cur;
            }else{
                n=n->next;
            }
            f=false;
            if(!cur)break;
            cur=cur->next;
        }
        ListNode* ret=sn->next;delete sn;
        return ret;
    }
};