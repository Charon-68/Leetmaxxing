class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int temp1 = st.top(); st.pop();
                int temp2 = st.top(); st.pop();

                if(s == "+"){
                    st.push(temp2 + temp1);
                }
                if(s == "-"){
                    st.push(temp2 - temp1);
                }
                if(s == "*"){
                    st.push(temp2 * temp1);
                }
                if(s == "/"){
                    st.push(temp2 / temp1);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};