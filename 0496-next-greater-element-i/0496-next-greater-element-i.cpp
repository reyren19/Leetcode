class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>mpp;
        int n = nums2.size();
        vector<int> ans;
        for(int i=n-1; i>=0; --i){
            // here we will maintain a monotonic decreasing stack where we keep the elements greater than current and pop till all lesser ones are gone
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                mpp[nums2[i]]=-1;
            }
            else{
                mpp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int num: nums1){
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};