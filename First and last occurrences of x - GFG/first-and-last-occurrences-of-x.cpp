// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
  vector<int> v;
  int start=0;
  int end=n-1;

  int ans1=-1;
  
  //left 
  while(start<=end){
      
        int mid=start+(end-start)/2;
      if(arr[mid]==x){
          ans1=mid;
          end=mid-1;
      }
      else if(x>arr[mid]){
          start=mid+1;
      }
      else if(x<arr[mid]){
          end=mid-1;
      }
      mid=(start+end)/2;
  }
  v.push_back(ans1);
  
  
  //right
  int start1=0;
  int end1=n-1;
  
  int ans2=-1;
   while(start1<=end1){
       int mid1=start1+(end1-start1)/2;
      if(arr[mid1]==x){
          ans2=mid1;
          start1=mid1+1;
      }
      else if(x>arr[mid1]){
          start1=mid1+1;
      }
      else if(x<arr[mid1]){
          end1=mid1-1;
      }
      
  }
  v.push_back(ans2);
  return v;
  
  
      
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends