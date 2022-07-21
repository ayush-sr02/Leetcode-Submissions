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
        if(!head) return nullptr;
        ListNode* prev=NULL;
        ListNode* cur=head;
        while(left>1){
            prev=cur;
            cur=cur->next;
            left--;right--;
        }
        ListNode* tail=cur;
        ListNode* connection = prev;
        while(right>0){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            right--;
        }
        if(connection!=NULL) connection->next=prev;
        else head = prev;
        tail->next=cur;
        return head;
    }
};