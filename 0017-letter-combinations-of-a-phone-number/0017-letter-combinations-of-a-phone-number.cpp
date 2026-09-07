class Solution {
public:
    vector<string> ans;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string digits, int index, string current) {

        // Base case
        if (index == digits.length()) {
            ans.push_back(current);
            return;
        }

        // Get letters for current digit
        string s = letters[digits[index] - '0'];

        // Try every letter
        for (char ch : s) {

            current.push_back(ch);

            solve(digits, index + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};