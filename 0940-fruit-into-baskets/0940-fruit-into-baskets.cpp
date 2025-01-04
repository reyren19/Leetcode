class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int maxLen=0;
        int i=0,j=0,n=fruits.size();
        while(j<n){
            mpp[fruits[j]]++;
            if(mpp.size()>2){
                mpp[fruits[i]]--;                
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            maxLen=max(j-i+1, maxLen);
            j++;
        }
        return maxLen;
    }
};