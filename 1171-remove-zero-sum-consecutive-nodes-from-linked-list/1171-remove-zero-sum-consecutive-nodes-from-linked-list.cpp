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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* node=new ListNode(-10);
        node->next=head;
        unordered_map<int,ListNode*> mp;
        int sum=0;
        for(auto i=node;i!=NULL;i=i->next){
            sum+=i->val;
            mp[sum] = i;
        }
        sum=0;
        for(auto i=node;i!=NULL;i=i->next){
            i->next=mp[sum+=i->val]->next;
        }
        return node->next;
    }
};