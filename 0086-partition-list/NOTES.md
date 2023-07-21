class Solution {
public:
ListNode* partition(ListNode* head, int x) {
ListNode* slow = head;
ListNode* cur=head;
ListNode* prev=NULL;
while(cur){
if(cur->val>=x) {
cur=cur->next;
}
else{
ListNode* temp = slow->next;
ListNode* next = cur->next;
slow->next=cur;
cur->next=temp;
temp->next=next;
cur=temp->next;
slow=slow->next;
}
}
return head;
}
};