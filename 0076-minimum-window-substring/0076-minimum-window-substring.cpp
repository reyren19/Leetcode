class Solution {
public:
    /* 
        > Add frequencies of chars of t in a map
        > Using sliding window, store all the substrings that follow criteria in a vector
        > Return the one with min len
    */

    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        unordered_map<char,int> window;
        if(t==""){
            return "";
        }
        int have=0,need=0;
        // Initialize the map with frequencies of t
        for (char c : t) {
            mpp[c]++;
        }
        need = mpp.size();
        int i = 0, j = 0;
        int n = s.size();
        int startIndex = 0;
        int minLen = INT_MAX;

        while (j < n) {
            // Decrease frequency of the current character
            if (mpp.find(s[j]) != mpp.end()) {
                window[s[j]]++;
                if(window[s[j]]==mpp[s[j]]){
                    have++;
                }
            }

            // Check if current window is valid
            while (have==need) {
                // Update the shortest substring if the current one is smaller
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIndex = i;
                }

                // Shrink the window from the left
                if (mpp.find(s[i]) != mpp.end()) {
                    window[s[i]]--;
                    if(window[s[i]]<mpp[s[i]]){
                        have--;
                    }                    
                }
                i++;
            }
            j++;
        }

        return minLen==INT_MAX?"":s.substr(startIndex, minLen);
    }
};
