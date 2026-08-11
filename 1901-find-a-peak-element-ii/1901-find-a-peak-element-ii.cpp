class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = rows - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Find maximum element in middle row
            int maxCol = 0;

            for (int j = 1; j < cols; j++) {
                if (mat[mid][j] > mat[mid][maxCol]) {
                    maxCol = j;
                }
            }

            int up = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int down = (mid < rows - 1) ? mat[mid + 1][maxCol] : -1;

            // Check if current cell is a peak
            if (mat[mid][maxCol] > up &&
                mat[mid][maxCol] > down) {

                return {mid, maxCol};
            }

            // Bigger element is above
            if (up > mat[mid][maxCol]) {
                high = mid - 1;
            }

            // Bigger element is below
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};