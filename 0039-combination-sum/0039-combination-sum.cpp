class Solution {
public:
void solve(int index, int target, vector<int>& candidates,
vector<int>& current, vector<vector<int>>& ans) {


    // Base case
    if (target == 0) {
        ans.push_back(current);
        return;
    }

    // No candidates left
    if (index == candidates.size()) {
        return;
    }

    // Pick the current number
    if (candidates[index] <= target) {
        current.push_back(candidates[index]);

        // Same index because we can reuse the number
        solve(index, target - candidates[index],
              candidates, current, ans);

        // Backtrack
        current.pop_back();
    }

    // Don't pick the current number
    solve(index + 1, target,
          candidates, current, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;

    solve(0, target, candidates, current, ans);

    return ans;
}


};
