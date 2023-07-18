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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = temp;
        while(head!=NULL){
            while(head->next and head->val==head->next->val) head=head->next;
            temp->next = head->next;
            temp = temp->next;
            head = head->next;
        }
        return dummy->next;
    }
};