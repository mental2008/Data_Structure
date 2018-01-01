#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
template<typename T>
void SelectionSort(T A[], int n) {
    for(int i = 0; i < n; ++i) {
        int index = i;
        for(int j = n - 1; j > i; --j) {
            if(A[j] < A[index]) index = j;
        }
        if(index != i) {
            T temp = A[index];
            A[index] = A[i];
            A[i] = temp;
        }
    }
}
#endif
