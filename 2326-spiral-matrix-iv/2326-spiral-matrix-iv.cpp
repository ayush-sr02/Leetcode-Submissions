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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m,vector<int>(n,-1));
        int r1 = 0, r2 = m-1;
        int c1 = 0, c2 = n-1;
        int val = 0;
        while(r1 <= r2 && c1 <= c2){
            for(int i = c1; i <= c2; ++i){
                if(head!=NULL) {
                    v[r1][i] = head->val;
                    head=head->next;
                }
                else return v;
            }
            for(int i = r1+1; i <= r2; ++i){
                if(head!=NULL) {
                    v[i][c2] = head->val;
                    head=head->next;
                }else return v;
            }
            if(r1 < r2 && c1 < c2)
            {
                for(int i = c2-1; i>c1; --i){
                    if(head!=NULL){
                        v[r2][i] = head->val;
                        head=head->next;
                    }else return v;
                }
                    
					
				for(int i = r2; i>r1; --i){
                    if(head!=NULL){
                        v[i][c1] = head->val;
                        head=head->next;
                    }else return v;
                } 
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
        
    }
};