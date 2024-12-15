class Solution {
public:
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int count=0;
        int maxCount =INT_MIN;
        int n = s.size();
        int i=0,j=0;
        while(j<n){
            if(isVowel(s[j])){
                count++;
            }
            if(j-i+1>k){
                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }
            if(j-i+1==k){
                maxCount = max(count,maxCount);
            }
            j++;
        }
        return maxCount;
    }
};