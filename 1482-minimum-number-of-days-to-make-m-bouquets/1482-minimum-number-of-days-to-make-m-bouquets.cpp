class Solution {
public:
    // Check if it is possible to make m bouquets by 'day'
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;   // Start counting for the next bouquet
                }
            } else {
                flowers = 0;       // Consecutive flowers are broken
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long requiredFlowers = 1LL * m * k;

        // Impossible to make m bouquets
        if (requiredFlowers > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;    // Try to find a smaller valid day
            } else {
                low = mid + 1;     // Need more days
            }
        }

        return ans;
    }
};