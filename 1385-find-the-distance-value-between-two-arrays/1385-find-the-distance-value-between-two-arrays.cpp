class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1,
                             vector<int>& arr2,
                             int d) {

        sort(arr2.begin(), arr2.end());

        int count = 0;

        for (int x : arr1) {

            int low = 0;
            int high = arr2.size() - 1;
            int ans = arr2.size();

            // Manual lower_bound implementation
            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (arr2[mid] >= x) {
                    ans = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            bool valid = true;

            // Check the first element >= x
            if (ans < arr2.size() &&
                abs(arr2[ans] - x) <= d) {
                valid = false;
            }

            // Check the element immediately before it
            if (ans > 0 &&
                abs(arr2[ans - 1] - x) <= d) {
                valid = false;
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};