class Solution {
public:

    void solve(string& num, long long target, int index,
               string expression, long long value,
               long long prev, vector<string>& ans) {

        if (index == num.size()) {
            if (value == target)
                ans.push_back(expression);
            return;
        }

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long current = stoll(part);

            if (index == 0) {

                solve(num, target, i + 1,
                      expression + part,
                      current, current, ans);

            }
            else {

                solve(num, target, i + 1,
                      expression + "+" + part,
                      value + current,
                      current, ans);

                solve(num, target, i + 1,
                      expression + "-" + part,
                      value - current,
                      -current, ans);

                solve(num, target, i + 1,
                      expression + "*" + part,
                      value - prev + prev * current,
                      prev * current, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(num, target, 0, "", 0, 0, ans);

        return ans;
    }
};