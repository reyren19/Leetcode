class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mpp;

        // Count frequency of each task
        for (char task : tasks) {
            mpp[task]++;
        }

        // Max-heap: highest frequency task on top
        priority_queue<int> maxHeap;

        for (auto& it : mpp) {
            maxHeap.push(it.second);
        }

        int count = 0;

        while (!maxHeap.empty()) {

            // Tasks that were processed in this cycle
            // and still have work remaining
            vector<int> waiting;

            // One cycle has n + 1 slots
            for (int i = 0; i <= n; i++) {

                // Schedule a task if one is available
                if (!maxHeap.empty()) {

                    int x = maxHeap.top();
                    maxHeap.pop();

                    x--;  // one occurrence is processed

                    if (x > 0) {
                        waiting.push_back(x);
                    }
                }

                // Time passes even if we were idle
                count++;

                // Everything is finished
                if (maxHeap.empty() && waiting.empty()) {
                    break;
                }
            }

            // Tasks that finished cooldown become available again
            for (int x : waiting) {
                maxHeap.push(x);
            }
        }

        return count;
    }
};