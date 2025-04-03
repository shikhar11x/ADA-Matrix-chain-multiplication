#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>&arr,int n){
    vector<vector<int>>dp(n,vector<int>(n,0));
    int stepCount=0;
    for(int i=n-1;i>0;i--) {
        for(int j=i+1;j<n;j++){
            dp[i][j]=INT_MAX;stepCount++;
            for(int k=i;k<j;k++){
                int cost=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];stepCount++;
                dp[i][j]=min(dp[i][j],cost);stepCount++;
            }
        }
    }cout<<"Steps: "<<stepCount<<endl;
    return dp[1][n-1];
}
void analysis(){
    vector<int>arr={4,5,6,7,8,9,10};
    int n=arr.size();
    for(int i=0;i<n;i++){
        vector<int>temp(arr[i]);
        for(int j=0;j<temp.size();j++){
            temp[j]=(j+1)*10;}
        // for(int j=0;j<temp.size();j++){
        //     cout<<temp[j]<<" ";}    
        // cout<<endl;
        cout<<"Minimum number of multiplications needed for "<<arr[i]<<" matrices: "<<matrixChainMultiplication(temp,arr[i])<<endl;

    }

}

int main(){
   analysis();
    return 0;
}
