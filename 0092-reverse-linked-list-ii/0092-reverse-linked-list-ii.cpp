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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* cur=head;
        ListNode* pre=NULL;
        while(cur and left>1){
            left--;right--;
            pre=cur;
            cur=cur->next;
        }
        ListNode* link=pre;
        ListNode* temp=cur;
        while(cur and right>0){
            right--;
            ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        temp->next=cur;
        if(link) link->next=pre;
        else head=pre;
        return head;
    }
};