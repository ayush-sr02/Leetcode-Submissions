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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* great = new ListNode(-1);
        ListNode* l=less,*g=great;
        ListNode* cur=head;
        while(cur){
            if(cur->val<x){
                less->next=cur;
                less=less->next;
            }else{
                great->next=cur;
                great=great->next;
            }
            cur=cur->next;
        }
        great->next=NULL;
        less->next = g->next;
        return l->next;
    }
};