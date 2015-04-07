#include <iostream>
using namespace std;

inline int parent(int i) {
    return (i/2);
}
inline int left(int i) {
    return 2*i;
}
inline int right(int i) {
    return 2*i + 1;
}
inline void exchange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(int arr[],int m) {
    cout << "[";
    for(int i = 1 ; i < m; i++) {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}

//parameter i is the root of the tree you want to make it to a heap

void max_heapify(int arr[],int n, int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= heap_size && arr[i] < arr[l]) {
        largest = l;
    }
//    notice here, the 3rd compares with the larger one,not the i-th node
    if(r <= heap_size && arr[largest] < arr[r]) {
        largest = r;
    }
    if(largest != i) {
        exchange(arr[i], arr[largest]);
        max_heapify(arr,n,heap_size,largest);
    }
}

void max_heapify_non_recursive(int arr[],int n, int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
//    notice here: loop condition is both in heap range, not either!!!
    while(l <= heap_size && r <= heap_size) {
        if(arr[i] < arr[l]) {
            largest = l;
        }
        if(arr[largest] < arr[r]) {
            largest = r;
        }
        if(largest != i) {
            exchange(arr[i],arr[largest]);
            i = largest;
            l = left(i);
            r = right(i);
        }
        else {
            break;
        }
    }



}

void build_max_heap(int arr[],int n,int heap_size) {
    for(int i = (heap_size / 2); i > 0; i--) {
        max_heapify(arr,n,heap_size,i);
    }
}
void build_max_heap_non_recursive(int arr[],int n,int heap_size) {
    for(int i = (heap_size / 2); i > 0; i--) {
        max_heapify_non_recursive(arr,n,heap_size,i);
    }
}

void heap_sort_non_recursive(int arr[],int n) {
    int heap_size = n-1;
    build_max_heap_non_recursive(arr,n,heap_size);
    for(int i = heap_size; i >= 2; i--) {
        exchange(arr[1],arr[i]);
        heap_size--;
//         notice here, the start node is always the 1-st one.
        max_heapify_non_recursive(arr,n,heap_size,1);
    }
}
void heap_sort(int arr[],int n) {
    int heap_size = n-1;
    build_max_heap(arr,n,heap_size);
    for(int i = heap_size; i >= 2; i--) {
        exchange(arr[1],arr[i]);
        heap_size--;
//         notice here, the start node is always the 1-st one.
        max_heapify(arr,n,heap_size,1);
    }
}



int main() {
    int m = 11;
    // heap star at 1, and arr[0] is dummy, may be it can be used for store the heap size
    int arr[] = {-1,1,2,4,8,91,9,3,7,10,14};
    int arr2[m];
    for(int i = 0; i < m; i++) {
        arr2[i] = arr[i];
    }
    cout << "original array: \n";
    print(arr,m);
    print(arr2,m);
    heap_sort(arr,m);
//    max_heapify(arr,m,m-1,3);
//    build_max_heap(arr,m,m-1);
    cout << "recursive : \n";
    print(arr,m);

//    max_heapify_non_recursive(arr2,m,m-1,3);
//    build_max_heap(arr,m,m-1);
    heap_sort_non_recursive(arr2,m);
    cout << "non-recursive : \n";
    print(arr2,m);

    return 0;
}
