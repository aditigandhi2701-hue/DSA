class Solution {
public:

    long long subArrayMin(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || nums[st.top()] >= nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans += 1LL * nums[mid] * left * right;
            }

            st.push(i);
        }

        return ans;
    }

    long long subArrayMax(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        stack<int> st;

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || nums[st.top()] <= nums[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;

                ans += 1LL * nums[mid] * left * right;
            }

            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) - subArrayMin(nums);
    }
};