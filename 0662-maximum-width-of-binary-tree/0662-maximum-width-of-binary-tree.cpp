class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        unsigned long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();

            unsigned long long first = q.front().second;
            unsigned long long last = 0;

            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                unsigned long long idx = it.second - first;

                last = idx;

                if (node->left != NULL) {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right != NULL) {
                    q.push({node->right, 2 * idx + 2});
                }
            }

            ans = max(ans, last + 1);
        }

        return (int)ans;
    }
};