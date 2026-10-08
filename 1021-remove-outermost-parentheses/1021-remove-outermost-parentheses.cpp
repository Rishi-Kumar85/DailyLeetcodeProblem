class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int balance=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
          if(balance>0) res+=s[i];
            balance++;
        }
        else{
            balance--;
            if(balance>0) {
                res+=s[i];
            }
        }
    }
    return res;

    }
};