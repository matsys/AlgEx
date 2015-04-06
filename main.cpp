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
inline void exchange(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}



void max_heapify(int arr[],int n, int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int large = i;
    if(l <= heap_size && arr[i] < arr[l]) {
        large = l;
    }
    if(r <= heap_size && arr[i] < arr[r]) {
        large = r;
    }
    if(large != i) {
        exchange(arr[i], arr[large]);
        max_heapify(arr,n,heap_size,large);
    }
}

void build_max_heap(int arr[],int n,int heap_size){
    for(int i = (heap_size / 2); i > 0; i--){
        max_heapify(arr,n,heap_size,i);
    }
}
void print(int arr[],int m){
    cout << "[";
    for(int i = 1 ; i < m; i++){
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}


int main() {
    int m = 11;
    int arr[] = {-1,16,2,4,8,91,9,3,7,10,14};
    build_max_heap(arr,m,m-1);
    print(arr,m);
    return 0;
}
