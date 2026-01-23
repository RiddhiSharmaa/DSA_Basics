#include <iostream>
using namespace std;

class Heap{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity){
        this -> arr = new int[capacity];
        this -> capacity = capacity;
        this -> size = 0;
    }

    void insert(int val){
        if (size == capacity){
            cout << "Heap overflow";
            return;
        }
        size++;
        int idx = size;
        arr[idx] = val;

        while (idx > 1){
            if (arr[idx] > arr[idx/2]){
                swap(arr[idx], arr[idx/2]);
                idx = idx/2;
            } else{
                break;
            }
        }
    }

    void printHeap(){
        for (int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int deleteFromHeap(){
        int ans = arr[1];
        arr[1] = arr[size];
        size--;
        int idx = 1;

        while (idx < size){
            int left_idx = 2 * idx;
            int right_idx = 2 * idx + 1;
            int largest_idx = idx;

            if (left_idx <= size && arr[left_idx] > arr[largest_idx]){
                largest_idx = left_idx;
            } 
            if (right_idx <= size && arr[right_idx] > arr[largest_idx]){
                largest_idx = right_idx;
            }

            if (largest_idx == idx){
                break;
            }
            else{
                swap(arr[largest_idx], arr[idx]);
                idx = largest_idx;
            }
            
        }
        return ans;
    }
};

void heapify(int *arr, int size, int idx){
    int l_idx = 2 * idx;
    int r_idx = 2 * idx + 1;
    int largest_idx = idx;

    if (l_idx <= size && arr[l_idx] > arr[largest_idx]){
        largest_idx = l_idx;
    }
    if (r_idx <= size && arr[r_idx] > arr[largest_idx]){
        largest_idx = r_idx;
    }

    if (idx == largest_idx) return;

    if (idx != largest_idx){
        swap(arr[idx], arr[largest_idx]);
        idx = largest_idx;
        heapify(arr, size, idx);
    }
}

void buildHeap(int *arr, int size){
    for (int i = size/2; i > 0; i--){
        heapify(arr, size, i);
    }
}

void heapSort(int *arr, int n){
    while (n > 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main(){
    Heap h(10);
    
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    h.printHeap();

    int ans = h.deleteFromHeap();
    cout << "ans: " << ans << endl;
    h.printHeap();

    int arr[] = {-1, 5, 10, 30, 25, 12};
    int n = 5;

    buildHeap(arr, n);
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}