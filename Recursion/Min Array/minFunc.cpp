#include "minFunc.h"
#include <iostream>
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0) return nullptr;
    if (arrSize == 1) {
        return 0;
    } 
    const int* index = min(arr+1, arrSize -1)+1;
    if (arr[0] > arr[*index]) return index;
    return 0;
}