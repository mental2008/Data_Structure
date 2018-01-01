#ifndef BUBBLESORT_H
#define BUBBLESORT_H
template<typename T>
void BubbleSort(T A[], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = n - 1; j > i; --j) {
            if(A[j - 1] > A[j]) {
                T temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
    }
}
#endif
