# Heap Sort

This sorting technique is based on *Binary Heap* data structure. There's a terminology used in this technique called ***heapify*** which refers to *restoring
the heap property*.  
![heap-property-explanation](https://github.com/sahsan73/cp/blob/main/SortingTechniques/assets/images/heap-sort-part-1.png)   

**Procedures:**   
Step - I: Create max/min heap from the given input array (we'll use max heap in this example)     
![create-max-heap](https://github.com/sahsan73/cp/blob/main/SortingTechniques/assets/images/heap-sort-part-2.png)   

Step - II: Delete the root node i.e., the maximum element in the heap followed by heapifying the tree.   
Note - Whenever the root element is removed from the heap, always last leaf node takes the position before heapifying.   
![sort-array-with-deleting](https://github.com/sahsan73/cp/blob/main/SortingTechniques/assets/images/heap-sort-part-3.png)   

Step - III: Repeat the Step-II n times, where n is the number of elements   

#### Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e5;
int n, a[mxN];

void heapify(int n, int i) {
    int mx=i; // index of maximum child
    
    int left=2*i+1; // left child index
    int right=2*i+2; // right child index
    if(left<n&&a[left]>a[mx])
        mx=left;
    if(right<n&&a[right]>a[mx])
        mx=right;
    
    if(mx^i) {
        swap(a[i], a[mx]);
        heapify(n, mx);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    // build heap
    for(int i=n/2-1; ~i; --i)
        heapify(n, i);
    
    // heap sort
    for(int i=n-1; ~i; --i) {
        swap(a[i], a[0]);
        heapify(i, 0);
    }
    for(int i=0; i<n; ++i)
        cout << a[i] << " ";
    cout << "\n";
    
    return 0;
}
```

Here is the [problem](https://www.geeksforgeeks.org/problems/heap-sort/1?page=2&company=Oracle&sortBy=submissions) on GeeksforGeeks to try!
