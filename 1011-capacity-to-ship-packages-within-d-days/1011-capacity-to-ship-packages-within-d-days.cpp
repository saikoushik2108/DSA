class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int mid) {

        int countDays = 1;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++) {

            if(sum + weights[i] <= mid) {
                sum += weights[i];
            }
            else {
                countDays++;
                sum = weights[i];
            }
        }

        return countDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};