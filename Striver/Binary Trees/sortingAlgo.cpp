#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}

void print(vector<int> &arr,int startIn,int endIn)
{
    for(int i=startIn;i<=endIn;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {5,2,3,1,9,2,11,0};
    return 0;
}

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[index] > arr[j])
                index = j;
        }
        swap(arr[index], arr[i]);
    }
}

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = val;
    }
}

void merge(vector<int> &arr, int startIn, int middleIn, int endIn)
{
    vector<int> subArr1;
    for (int i = startIn; i <= middleIn; i++)
        subArr1.push_back(arr[i]);
    vector<int> subArr2;
    for (int j = middleIn + 1; j <= endIn; j++)
        subArr2.push_back(arr[j]);
    int i = 0;
    int j = 0;
    int size1 = middleIn - startIn + 1;
    int size2 = endIn - middleIn;
    int arrIn = startIn;
    while (i < size1 && j < size2)
    {
        if (subArr1[i] > subArr2[j])
        {
            arr[arrIn] = subArr2[j];
            arrIn++;
            j++;
        }
        else
        {
            arr[arrIn] = subArr1[i];
            arrIn++;
            i++;
        }
    }
    while (i < size1)
    {
        arr[arrIn] = subArr1[i];
        i++;
        arrIn++;
    }
    while (j < size2)
    {
        arr[arrIn] = subArr2[j];
        j++;
        arrIn++;
    }

    // Method 2 to merge 2 arrays
    // int i =startIn,j=middleIn+1;
    // vector<int>arr3;
    // while(i<=middleIn && j<=endIn){
    //     if(arr[i]<arr[j]){
    //         arr3.push_back(arr[i]);
    //         i++;
    //     }else{
    //         arr3.push_back(arr[j]);
    //         j++;
    //     }
    // }
    // if (i > middleIn)
    // {
    //     for (; j <= endIn; j++)
    //     {
    //         arr3.push_back(arr[j]);
    //     }
    // } else if (j > endIn)
    // {
    //     for (; i <=middleIn; i++)
    //     {
    //         arr3.push_back(arr[i]);
    //     }
    // }
    // j = 0;
    // for(int i=startIn;i<=endIn;i++){
    //     arr[i] = arr3[j];
    //     j++;
    // }
}

void mergeSort(vector<int> &arr, int startIn, int endIn)
{
    if (startIn == endIn)
        return;
    int middleIn = (startIn + endIn) / 2;
    mergeSort(arr, startIn, middleIn);
    mergeSort(arr, middleIn + 1, endIn);
    merge(arr, startIn, middleIn, endIn);
}

void quickSort(vector<int> &arr, int startIn, int endIn)
{
    if (startIn >= endIn)
        return;
    // int p = startIn + 1, q = endIn;
    // while (true)
    // {
    //     while (p <= endIn && arr[p] < arr[startIn])
    //             p++;
    //     while (arr[q] > arr[startIn] && q >= startIn)
    //         q--;
    //     if (p < q)
    //         swap(arr[p], arr[q]);
    //     else
    //     {
    //         swap(arr[startIn], arr[q]);
    //         break;
    //     }
    // }

    // Alternative Way:
    int pivot = arr[startIn];
    int q = endIn; //Here, q gives the correct position at which element is inserted
    for (int i = endIn; i > startIn; i--)
    {
        if (arr[i] > pivot) swap(arr[i], arr[q--]);
    }
    swap(arr[startIn], arr[q]);

    quickSort(arr, startIn, q - 1);
    quickSort(arr, q + 1, endIn);
}



