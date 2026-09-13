class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> current;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    current.push_back(nums[i]);
                }
            }

            ans.push_back(current);
        }

        return ans;
    }
};