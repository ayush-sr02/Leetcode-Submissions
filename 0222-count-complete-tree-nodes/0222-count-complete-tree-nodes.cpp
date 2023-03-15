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
    int countNodes(TreeNode* root) {
        int leftheight = left(root);
        int rightheight = right(root);
        if(leftheight==rightheight) return (1<<leftheight)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int left(TreeNode* root){
        int h=0;
        while(root){
            root=root->left;
            h++;
        }
        return h;
    }
    int right(TreeNode* root){
        int h=0;
        while(root){
            root=root->right;
            h++;
        }
        return h;
    }
};