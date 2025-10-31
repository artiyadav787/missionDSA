class Solution {
public:
    vector<int> arr;
    
    TreeNode* build(int l, int r) {
        if(l>r) return nullptr;
        int m = (l+r)/2;
        TreeNode* root = new TreeNode(arr[m]);
        root->left = build(l, m-1);
        root->right = build(m+1, r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        return build(0, arr.size()-1);
    }
};
