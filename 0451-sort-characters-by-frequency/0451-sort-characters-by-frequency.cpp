class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency of every character
        for (char c : s) {
            freq[c]++;
        }

        // Bucket: index = frequency
        vector<vector<char>> bucket(s.size() + 1);

        for (auto& [ch, count] : freq) {
            bucket[count].push_back(ch);
        }

        string ans;

        // Start from highest frequency
        for (int count = s.size(); count >= 1; count--) {
            for (char ch : bucket[count]) {
                ans.append(count, ch);
            }
        }

        return ans;
    }
};