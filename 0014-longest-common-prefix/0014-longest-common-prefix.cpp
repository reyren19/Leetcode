class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort strings lexographically
        // compare first and last strings 
        string ans = ""; 
        int n = strs.size();
        sort(strs.begin(), strs.end());
        for(int i=0; i<strs[0].length(); i++){
            if(strs[0][i]==strs[n-1][i]){
                ans += strs[0][i]; 
            }
            else{
                break;
            }
        }   
        return ans;
    }
};