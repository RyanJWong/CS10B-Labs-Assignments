#include "minFunc.h"
#include <iostream>
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }
    if (arrSize <= 1) {
        return &arr[0];
    } 
    const int * small = min(arr, arrSize -1);
    if (arr[arrSize-1] > *small) return small;
    return &arr[arrSize-1];
}