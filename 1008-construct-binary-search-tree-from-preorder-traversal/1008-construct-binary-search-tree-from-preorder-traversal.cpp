class Solution {
public:
    TreeNode* build(int &i, vector<int>& preorder,
                    long long lower, long long upper) {

        // All elements are processed
        if (i == preorder.size()) {
            return nullptr;
        }

        // Current value is outside the allowed range
        if (preorder[i] < lower || preorder[i] > upper) {
            return nullptr;
        }

        // Create the root node
        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        // Construct left subtree
        root->left = build(i, preorder, lower, root->val);

        // Construct right subtree
        root->right = build(i, preorder, root->val, upper);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;

        return build(i, preorder, LLONG_MIN, LLONG_MAX);
    }
};