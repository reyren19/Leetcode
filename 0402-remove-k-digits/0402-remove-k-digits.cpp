class Solution {
public:
    string removeKdigits(string num, int k) {
        /* 
        INTUITION-
        We need to make sure that the starting digits are the lowest
        For this we can use a stack, before storing a digit, check if it is less    than the current one, if yes pop it then push the current one.
        */
        stack<char>s;
        string res = "";
        for(int i=0; i<num.size(); i++){
            while(!s.empty() && k>0 && (s.top()-'0') > num[i]-'0'){
                s.pop();
                k--;
            } 
            s.push(num[i]);
        }
        // checking this in case of strings like 12345 where every other number is bigger than the other so nothing gets popped out
        while(k!=0){
            s.pop();
            k--;
        }
        if(s.empty()){
            return "0";
        }
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        if(res==""){
            return "0";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};