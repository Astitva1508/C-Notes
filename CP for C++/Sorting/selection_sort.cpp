#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int minElementIndex = i+1;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[minElementIndex])
                minElementIndex = j;
        }
        if (minElementIndex != i){
            int temp = arr[i];
            arr[i] = arr[minElementIndex];
            arr[minElementIndex] = temp;
        }
    }
    for (int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
