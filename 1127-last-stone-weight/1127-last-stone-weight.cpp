class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end()); // heapifyinbg the vector
        while(maxHeap.size()>1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();
            if(stone1!=stone2){
                stone2 = stone1-stone2;
                maxHeap.push(stone2);
            }
        }
        return maxHeap.empty() ? 0: maxHeap.top();
    }
};