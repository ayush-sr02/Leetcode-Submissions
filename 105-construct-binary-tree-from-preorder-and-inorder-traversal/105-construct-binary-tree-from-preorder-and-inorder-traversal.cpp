/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end){
        
        if(start>end) return NULL;
        int curr = preorder[idx];
        idx++;
        TreeNode* node = new TreeNode(curr);
        int pos ;
        for(int i=start;i<=end;i++){
            if(inorder[i]==curr){
                pos=i;
                break;
            }
        }
        // if(start==end) return node;
        node->left = build(preorder,inorder,start,pos-1);
        node->right = build(preorder,inorder,pos+1,end);
        return node;
    }
};