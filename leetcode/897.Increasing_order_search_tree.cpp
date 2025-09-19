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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);  // temporary dummy root
        TreeNode* curr = dummy;
        
        inorder(root, curr);
        
        return dummy->right;  // new root (smallest value)
    }
    
    void inorder(TreeNode* node, TreeNode*& curr) {
        if (!node) return;
        
        inorder(node->left, curr);   // left
        
        node->left = nullptr;        // remove left child
        curr->right = node;          // attach to the right
        curr = node;                 // move forward
        
        inorder(node->right, curr);  // right
    }
};
