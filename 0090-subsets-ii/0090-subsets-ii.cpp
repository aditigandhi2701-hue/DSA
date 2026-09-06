class Solution {
public:

    void solve(int start, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Every current combination is a valid subset
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate values at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Pick
            current.push_back(nums[i]);

            // Move to next index
            solve(i + 1, nums, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        // Sort so duplicates come together
        sort(nums.begin(), nums.end());

        solve(0, nums, current, ans);

        return ans;
    }
};