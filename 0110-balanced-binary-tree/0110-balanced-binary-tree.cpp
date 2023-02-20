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
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        int leftHeight = height(root->left);
        if(leftHeight==-1) return -1;
        int rightHeight = height(root->right);
        if(rightHeight==-1) return -1;
        if(abs(leftHeight-rightHeight)>1) return -1;
        return 1+max(leftHeight,rightHeight);
    }
    
    // bool solve(TreeNode* root){
    //     if(root==NULL) return true;
    //     int lheight = height(root->left);
    //     int rheight = height(root->right);
    //     if(abs(lheight-rheight)>1) return false;
    //     // bool left = solve(root->left);
    //     // bool right = solve(root->right);
    //     // if(left==false or right==false) return false;
    //     // return true;
    //     return solve(root->left) and solve(root->right);
    // }
    
    bool isBalanced(TreeNode* root) {
        return height(root)==-1?false:true;
    }
};