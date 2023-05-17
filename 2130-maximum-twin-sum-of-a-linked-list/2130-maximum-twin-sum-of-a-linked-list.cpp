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
    
    //reverse the second half of list then use 2 pointer to traverse simultaneously
    
    ListNode* reverse(ListNode* node){
        ListNode* prev=NULL;
        ListNode* cur=node;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        int ans=INT_MIN;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast and fast->next){
            slow=slow->next,fast=fast->next->next;
        }
        slow = reverse(slow);
        while(slow!=NULL){
            ans = max(ans,head->val+slow->val);
            head=head->next;
            slow=slow->next;
        }
        
        return ans;
    }
};