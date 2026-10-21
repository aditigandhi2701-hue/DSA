
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxGain(root, maxi);
        return maxi;
    }

    int maxGain(TreeNode* root, int &maxi) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = max(0, maxGain(root->left, maxi));
        int rightSum = max(0, maxGain(root->right, maxi));

        maxi = max(maxi, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
};
