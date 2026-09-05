class Solution {
public:

void solve(int start, int target,
           vector<int>& candidates,
           vector<int>& current,
           vector<vector<int>>& ans) {

    // Target reached
    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {

        // Skip duplicate values at the same level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Since array is sorted
        if (candidates[i] > target)
            break;

        // Pick
        current.push_back(candidates[i]);

        // i + 1 because each element can be used only once
        solve(i + 1,
              target - candidates[i],
              candidates,
              current,
              ans);

        // Backtrack
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates,
                                    int target) {

    vector<vector<int>> ans;
    vector<int> current;

    sort(candidates.begin(), candidates.end());

    solve(0, target, candidates, current, ans);

    return ans;
}

};
