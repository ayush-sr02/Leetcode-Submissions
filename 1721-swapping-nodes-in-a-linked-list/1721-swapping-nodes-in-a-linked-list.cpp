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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left=head;
        ListNode* right=head;
        int x=1;
        ListNode* cur=head;
        while(cur!=NULL){
            if(x<k) left=left->next;
            if(x>k) right=right->next;
            x++;
            cur=cur->next;
        }
        int temp=left->val;
        left->val=right->val;
        right->val=temp;
        return head;
    }
};