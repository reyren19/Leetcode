class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(st.size()!=0){
            char topSt = st.top();
            if((s[i]==')' && topSt=='(') || (s[i]=='}' && topSt=='{') || (s[i]==']' && topSt=='[')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            }
           else{
            st.push(s[i]);
           }
        }
        return (st.size()==0);
    }
};