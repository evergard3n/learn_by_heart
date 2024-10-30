#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

// void merge(int arr[], int const left, int const mid, int const right) {
//     int const leftArrayL = mid-left+1;
//     int const rightArrayL = right - mid;
//     auto *leftArray = new int[leftArrayL];
//     auto *rightArray = new int[rightArrayL];
//     for(auto i=0;i<leftArrayL;i++) {
//         leftArray[i] = arr[left+i];
//     }
//     for(auto j=0;j<rightArrayL;j++) {
//         rightArray[j] = arr[mid+j+1];
//     }
//     auto leftArrInd = 0, rightArrInd =0;
//     int mergedArrInd = left;
//     while(leftArrInd < leftArrayL && rightArrInd < rightArrayL) {
//         if(leftArray[leftArrInd] <= rightArray[rightArrInd]) {
//             arr[mergedArrInd] = leftArray[leftArrInd];
//             leftArrInd++;
//         }
//         else {
//             arr[mergedArrInd] = rightArray[rightArrInd];
//             rightArrInd++;
//         }
//         mergedArrInd++;
//     }
//     while(leftArrInd<=leftArrayL) {
//         arr[mergedArrInd] = leftArray[leftArrInd];
//             leftArrInd++;
//             mergedArrInd++;
//     }
//     while(rightArrInd<=rightArrayL) {
//         arr[mergedArrInd] = rightArray[rightArrInd];
//             rightArrInd++;
//             mergedArrInd++;
//     }
//     delete[] leftArray;
//     delete[] rightArray;
// }
// void mergeSort(int arr[], int const left, int const right) {
//     if(left >= right) {
//         return;
//     }
//     int mid = left + (right-left)/2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid+1,right);
//     merge(arr, left, mid, right);
// }
void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    } 
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void printArray(int arr[], int arr_size) {
    for(int i=0; i<arr_size;i++) {
        std::cout << arr[i] <<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    std::cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    std::cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}