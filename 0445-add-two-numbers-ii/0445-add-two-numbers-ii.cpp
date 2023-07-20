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
        ListNode* cur = node;
        ListNode* prev = NULL;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode* ans = new ListNode(-1);
        ListNode* dummy = ans;      
        int carry=0;
        while(l1 or l2 or carry){
            int x=carry;
            if(l1!=NULL) {
                x+=l1->val;
                l1=l1->next;
            }
            if(l2){
                x+=l2->val;
                l2=l2->next;
            }
            ans->next = new ListNode(x%10);
            ans=ans->next;
            carry=x/10;
        }
        return reverse(dummy->next);
    }
};