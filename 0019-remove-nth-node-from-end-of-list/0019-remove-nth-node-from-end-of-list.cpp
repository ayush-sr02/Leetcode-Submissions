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
    ListNode* reverse(ListNode* node){
        ListNode* cur=node;
        ListNode* prev=NULL;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head or !head->next) return NULL;
        head=reverse(head);
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur and n>1){
            prev=cur;
            cur=cur->next;
            n--;
        }
        if(cur->next){
            cur->val=cur->next->val;
            cur->next=cur->next->next;
        }else prev->next=NULL;
        return reverse(head);
    }
};