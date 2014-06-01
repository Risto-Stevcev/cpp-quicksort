#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>
using namespace std;

class QuickSort;

class QuickSort
{
    public:

    QuickSort();
    QuickSort(const int*, int);
    ~QuickSort();

    friend ostream& operator<< (ostream&, const QuickSort&);
    int& operator[] (const int index);

    int& length (void);

    void quicksort (void);
    void _quicksort (int *, int, int);


    private:

    void swap (int *, int, int);
    int partition (int *, int, int, int);

    int* list;
    int len;
};

ostream& operator<< (ostream&, const QuickSort&);
void print_arr(int *, int);
#endif
