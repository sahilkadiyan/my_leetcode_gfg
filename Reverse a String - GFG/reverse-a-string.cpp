// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
 char temp;
   int len = str.length();
   if(len <= 1)
       return str;
   int start = 0;
   int end = len -1;
   
   while(start < end)
   {
       temp = str[end];
       str[end--] = str[start];
       str[start++] = temp;

   }
   
   return str;
}
  
  
