## Objective 
The objective of this assignment is to Implement Matrix Chain Multiplication Problem 
and measure the time required to Matrix Chain. 
## Problem Description 
### 1. Task: 
i. Write a program to implement Matrix Chain Multiplication Problem. 
ii. Measure the time required to multiply a Matrix Chain. 
iii. Analyze the time complexity by varying the input size. 
iv. Plot graphs for input size vs. time taken. 
### 2. Input: 
• A list and dimensions of a set of matrices. 
• Perform matrix chain multiplication for different input sizes. 
### 3. Output: 
• Time taken for multiply a Matrix Chain. 
• Graph of time taken versus input size.
## code 
```cpp
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

int main() {
   analysis();
    return 0;
}
```
## Output
```
Steps: 11
Minimum number of multiplications needed for 4 matrices: 18000
Steps: 26
Minimum number of multiplications needed for 5 matrices: 38000
Steps: 50
Minimum number of multiplications needed for 6 matrices: 68000
Steps: 85
Minimum number of multiplications needed for 7 matrices: 110000
Steps: 133
Minimum number of multiplications needed for 8 matrices: 166000
Steps: 196
Minimum number of multiplications needed for 9 matrices: 238000
Steps: 276
Minimum number of multiplications needed for 10 matrices: 328000
```
## Time Complexity
The time complexity of the above code is O(n^3) where n is the number of matrices.
## Graph
![](./graphs/Figure_1.png)
