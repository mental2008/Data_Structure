#ifndef SHELLSORT_H
#define SHELLSORT_H
template<typename T>
void inssort2(T A[], int n, int incr) {
    for(int i = incr; i < n; i += incr) {
        for(int j = i; j >= incr && (A[j] < A[j - incr]); j -= incr) {
            T temp = A[j];
            A[j] = A[j - incr];
            A[j - incr] = temp;
        }
    }
}

template<typename T>
void ShellSort(T A[], int n) {
    for(int i = n / 2; i > 2; i /= 2) {
        for(int j = 0; j < i; ++j) {
            inssort2(&A[j], n - j, i);
        }
    }
    inssort2(A, n, 1);
}
#endif
