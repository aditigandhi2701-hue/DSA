
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;

        dfs(root, 0, 0, nodes);

        vector<vector<int>> ans;

        for (auto &col : nodes) {
            vector<int> values;

            for (auto &row : col.second) {
                for (int val : row.second) {
                    values.push_back(val);
                }
            }

            ans.push_back(values);
        }

        return ans;
    }

    void dfs(TreeNode* root, int row, int col,
             map<int, map<int, multiset<int>>> &nodes) {
        if (root == NULL) {
            return;
        }

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }
};
