class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        long long ans = 0;
        const int MOD = 1e9 + 7;

        stack<int> st;

        vector<int> left(n), right(n);

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = i + 1;
            else
                left[i] = i - st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n - i;
            else
                right[i] = st.top() - i;

            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};