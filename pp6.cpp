#include<bits/stdc++.h>
using namespace std;
int crosssum(vector<int> &arr, int left , int right, int mid, int con){
    int sum=0; 
    int leftmx=INT_MIN;
    for (int i = mid; i >= left; i--)
    {
        sum+=arr[i];
    
    if(sum<=con) { leftmx = max(sum,leftmx);}}
 
    int rightmx=INT_MIN;
    sum=0;
    for (int i = mid+1; i <= right; i++)
    {
        sum+=arr[i];
    
    if(sum<=con) { rightmx= max(sum,rightmx);}}

    if(leftmx ==INT_MIN && rightmx==INT_MIN) return INT_MIN;
    if(leftmx==INT_MIN) return rightmx;
    if(rightmx==INT_MIN) return leftmx;
    if(leftmx+rightmx<=con) return leftmx+rightmx;
    return max(leftmx,rightmx);
    
}
int subarray(vector<int> &arr, int left, int right,  int con){
    if(left==right){
        return(arr[left]<=con)?arr[left]:INT_MIN;
    }
  int  mid=(left+right)/2;
   int leftmx= subarray(arr,left,mid,con);
  int  rightmx =subarray(arr,mid+1,right,con);
  int crossum=crosssum(arr,left,right,mid,con);

  return max({leftmx,rightmx,crossum});


}
int main()
{

    int n;
    cout << "ENter size";
    cin>>n;
    vector<int> arr(n);
    int con;
    cout<<"enter constraint"<< endl;
    cin >> con;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=subarray(arr,0,n-1,con);
    if(result==INT_MIN){
        cout<<"NO maximum subarray"<<'\n';
    }
    else{
        cout<<result;
    }
   return 0;
}