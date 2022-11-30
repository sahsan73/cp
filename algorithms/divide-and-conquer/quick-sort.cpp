/*
APPROACH:
    - Select a pivot element (from end or start or mid) and place it on correct position in the array
    - Quick sort on left and right sides of the pivot element, excluding pivot element on both the cases since it is already sorted
*/
int partition_arr(int arr[], int s, int f) {
    int i = s-1, pivot = arr[f];
    for(int j=s; j<f; ++j) {
        if(arr[j] < pivot) {
            std::swap(arr[++i], arr[j]);
        }
    }
    
    std::swap(arr[++i], arr[f]);
    return i;
}

// s ==> start index of subarray
// f ==> finish index of subarray
void quick_sort(int arr[], int s, int f) {
    if(s>=f) return;
    
    int p = partition_arr(arr, s, f);
    
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, f);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
SOME PROBLEMS BASED ON THE QUICK SORT ALGORITHM:
    (1) Kth Largest Element in an Array
        Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
    
    (2) Sort Colors
        Link: https://leetcode.com/problems/sort-colors/

*/
