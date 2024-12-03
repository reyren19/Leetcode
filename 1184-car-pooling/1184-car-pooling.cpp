class Solution {
public:
    vector<int> applyDifference(vector<vector<int>>& trips) {
        vector<int> diff(1001, 0); // Difference array

        for (int i = 0; i < trips.size(); i++) {
            int num = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            diff[from] += num;
            if (to < 1001) {
                diff[to] -= num;
            }
        }

        // Convert difference array to prefix sum (passenger count at each location)
        vector<int> prefix(1001, 0);
        prefix[0] = diff[0];
        for (int i = 1; i < 1001; i++) {
            prefix[i] = prefix[i - 1] + diff[i];
        }
        return prefix;
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengerCount = applyDifference(trips);

        for (int i = 0; i < passengerCount.size(); i++) {
            if (passengerCount[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};
