class Solution {
public:
   int atoi(string s){
       int l = s.size();
       int sig = 1,i=0;
       int sum=0;
       if(s[i]=='-'){
           sig = -1;
           i++;
       }
       while(i<l) sum = sum*10+(s[i++]-'0');
       return sum*sig;
   }
   int evalRPN(vector<string>& tok) {
       int len = tok.size();
       stack<long> s;
       for(int i=0;i<len;i++){
           int l = tok[i].size();
           if(l>1) s.push(atoi(tok[i]));
           else if(isdigit(tok[i][0])) s.push(atoi(tok[i]));
           else{
               long a = s.top();
               s.pop();
               long b = s.top();
               s.pop();
               if(tok[i]=="/") s.push(b/a);
               else if(tok[i]=="+") s.push(a+b);
               else if(tok[i]=="*") s.push(a*b);
               else if(tok[i]=="-") s.push(b-a);
           }
       }
       return s.top();
   }
};