class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int i=0,j=0;
        int count = 0;
        int maxCount = 0;
        while(j<s.size()){  
            mpp[s[j]]++;
            count++;
            //handle duplicates
            if(mpp[s[j]]>1){
                while(mpp[s[j]]>1){
                    mpp[s[i]]--;
                    i++;
                    count--;
                }
            }
            //update maxcount
            maxCount=max(count,maxCount);                        
            j++;
        }
        return maxCount;
    }
};