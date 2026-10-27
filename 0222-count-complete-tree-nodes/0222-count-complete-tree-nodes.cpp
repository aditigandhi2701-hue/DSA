class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = 0, rh = 0;

        TreeNode* l = root;
        TreeNode* r = root;

        while (l) {
            lh++;
            l = l->left;
        }

        while (r) {
            rh++;
            r = r->right;
        }

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};