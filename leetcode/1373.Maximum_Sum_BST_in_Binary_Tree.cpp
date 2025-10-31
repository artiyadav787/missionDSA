class Solution {
public:
    int maxSum = 0;

    // returns {isBST, minVal, maxVal, sum}
    vector<int> dfs(TreeNode* root) {
        if (!root) 
            return {1, INT_MAX, INT_MIN, 0};  

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // check if subtree is BST
        if (left[0] && right[0] && left[2] < root->val && root->val < right[1]) {
            int sum = left[3] + right[3] + root->val;
            maxSum = max(maxSum, sum);
            return {1, min(left[1], root->val), max(right[2], root->val), sum};
        }

        // not BST -> mark invalid
        return {0, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
