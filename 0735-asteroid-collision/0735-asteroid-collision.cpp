class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for (int x : asteroids) {
            
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && x < 0) {
                
                if (st.top() < -x) {
                    st.pop();
                }
                else if (st.top() == -x) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(x);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};