class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        int value = node->val;

        pushAll(node->right);

        return value;
    }

    bool hasNext() {
        return !st.empty();
    }
};