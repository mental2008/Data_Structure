#ifndef INSERTIONSORT
#define INSERTIONSORT
template<typename T>
void InsertionSort(T A[], int n) {
    for(int i = 1; i < n; ++i) {
        for(int j = i; j > 0 && (A[j] < A[j - 1]); --j) {
            T temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
        }
    }
}
#endif
