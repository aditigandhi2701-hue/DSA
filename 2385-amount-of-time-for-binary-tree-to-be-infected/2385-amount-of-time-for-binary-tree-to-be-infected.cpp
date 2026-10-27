class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        TreeNode* startNode = nullptr;

        // Step 1: Build the parent map and find the start node
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start) {
                startNode = curr;
            }

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // Step 2: Spread infection using BFS
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Infect the left child
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // Infect the right child
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // Infect the parent
                if (parent[curr] && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
        }

        return minutes;
    }
};