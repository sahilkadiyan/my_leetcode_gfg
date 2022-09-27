class Solution {
public:
    string pushDominoes(string dominoes) {
        string a=dominoes;
          int n=a.size();
        vector<int>left(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        if(a[n-1]=='L'){
            left[n-1]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]=='R'){
                continue;
            }
            if(a[i]=='L'){
                left[i]=0;
            }else if(left[i+1]!=INT_MAX){
                left[i]=left[i+1]+1;
            }
        }
        if(a[0]=='R'){
            right[0]=0;
        }
        for(int i=1;i<n;i++){
            if(a[i]=='L'){
                continue;
            }
            if(a[i]=='R'){
                right[i]=0;
            }else if(right[i-1]!=INT_MAX){
                right[i]=right[i-1]+1;
            }
        }
        string s;
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                s+='.';
            }else if(left[i]<right[i]){
                s+='L';
            }else{
                s+='R';
            }
        }
        return s;
    }
};