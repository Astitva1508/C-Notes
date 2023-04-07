
#include<bits/stdc++.h>
using namespace std;

// Print all subsequences whose sum is k
// void printSumIsK(int index,vector<int> &numbers,vector<int> &ds,int n,int k,int sum){
//     if (index>=n){
//         if(sum==k){
//             for(auto it :ds){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//         }
//         return;
//     }
//     printSumIsK(index+1,numbers,ds,n,k,sum);

//     ds.push_back(numbers[index]);

//     printSumIsK(index+1,numbers,ds,n,k,sum+numbers[index]);
    
//     ds.pop_back();
// }

// Print any subsequence whose sum is k

// bool printSumIsK(int index, vector<int> &numbers, vector<int> &ds, int k,int sum,int size)
// {
//     if (index >= size)
//     {
//         if (sum == k)
//         {
//             for (int it : ds)
//                 cout << it << " ";
//             cout << endl;
//             return true;
//         }
//         return false;
//     }
//     ds.push_back(numbers[index]);
//     if (printSumIsK(index + 1, numbers, ds, k, sum + numbers[index],size)==true){
//         return true;
//     };
//     ds.pop_back();
//     if(printSumIsK(index + 1, numbers, ds, k, sum,size)==true) return true;
//     return false;
    
// }

// Print Count of all subSequences whose sum is K

// int countSumIsK(int index,vector<int> &numbers,int size, int k,int sum){
//     if (index==size){
//         if (sum==k){
//             return 1;
//         }
//         return 0;
//     }
//     int l = countSumIsK(index+1,numbers,size,k,sum+numbers[index]);
//     int r = countSumIsK(index+1,numbers,size,k,sum);
//     return l+r;
// }

int main(){
    vector<int> numbers = {1,2,2};
    vector<int> ds;
    return 0;
}

// Print SubSequences : 
// Two ways : parameterised, functional

// Print Only One SubSequence : 
// return true/false and avoid further recursive calls if the condition is satisfied

// Print count of subSequences satisfying a given condition : 
// return 1/0 and all function calls