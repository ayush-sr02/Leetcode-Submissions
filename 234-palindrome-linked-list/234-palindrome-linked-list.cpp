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
    int len(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        int l=len(head);
        stack<int> st;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast and fast->next){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(l%2!=0) slow=slow->next;
        while(slow!=nullptr){
            if(!st.empty() and slow->val!=st.top()) return false;
            slow=slow->next;
            st.pop();
        }
        return true;
    }
};