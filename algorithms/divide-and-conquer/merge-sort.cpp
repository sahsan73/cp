/*
APPROACH:
    - Divide the array into halves (disjoint/independent subproblems) recursively 
      until it becomes trivial to solve it directly i.e., when size becomes one.
    - Merge the two sorted subarrays at returning time
    
    - Time Complexity: O(nlogn)
    - Space Complexity: O(n)
*/
void merge_sort(int arr[], int low, int high) {
    if(low >= high) return;
    
    int mid = (low + high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    
    
    // merge two sorted arrays [low,...,mid] and [mid+1,...,high]
    int *aux = new int[high-low+1];
    int i = low, j = mid+1;
    int k = 0;
    while(i<=mid && j<=high) {
        if(arr[i] < arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    for(; i <= mid; ++i) aux[k++] = arr[i];     // if elements remain in left subarray [low,...,mid]
    for(; j <= high; ++j) aux[k++] = arr[j];    // if elements remain in [mid+1,...,high]
    
    for(i = low; i <= high; ++i) arr[i] = aux[i - low];   // update the original array
    delete [] aux;
}

/*
SOME PROBLEMS BASED ON MERGE SORT:
    - (1) Count Inversions
      Links: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?page=1&category[]=Divide%20and%20Conquer&sortBy=submissions
             https://codeforces.com/problemset/problem/1676/H2
          
    
    - (2) Reverse Pairs
          Link: https://leetcode.com/problems/reverse-pairs/
    
    - (3) Count of Smaller Numbers After Self
          Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
    


*/
