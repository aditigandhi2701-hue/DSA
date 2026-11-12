class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (last != nullptr) {
            swap(first->val, last->val);
        }
        else {
            swap(first->val, middle->val);
        }
    }
};