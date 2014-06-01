#include <iostream>
#include <cmath>
#include <cstdlib>
#include "QuickSort.h"

using namespace std;


QuickSort::QuickSort()
{
    list = new int[0];
    len = 0;
}


QuickSort::QuickSort (const int* t, int length)
{
    if (t) {
        len = length;
        list = new int[len];
        for (int i = 0; i < length; i++)
            list[i] = t[i];
    }
    else {
        list = new int[0];
        len = 0;
    }
}


QuickSort::~QuickSort()
{
    delete[] list;
}


ostream& 
operator<< (ostream& os, const QuickSort& ms)
{
    if (ms.len >= 1)
        os << ms.list[0];

    for (int i = 1; i < ms.len; i++)
        os << ", " << ms.list[i];

    os << endl;
    return os;
}


int& 
QuickSort::operator[] (const int index)
{
    return list[index];
}


int& 
QuickSort::length (void)
{
    return len;
}


void
print_arr(int *l, int len)
{
    for (int i = 0; i < len; i++)
        cout << l[i] << " ";
    cout << endl;
}


void
QuickSort::swap ( int *arr, int a, int b )
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int
QuickSort::partition ( int *arr, int left, int right, int pivotidx )
{
    int pivot = arr[pivotidx];
    swap( arr, right, pivotidx );

    for (int i = left; i < right; i++) {
        if (arr[i] < pivot) {
            swap( arr, i, left );
            left++;
        }
    }

    swap( arr, left, right );
    return left;
}


unsigned int
randr (unsigned int min, unsigned int max)
{
    double scaled = (double)rand()/RAND_MAX;
    return scaled*(max - min + 1) + min;
}


void
QuickSort::_quicksort ( int *arr, int left, int right )
{
    if (right > left) {
        int pivotidx = randr(left, right);
        pivotidx = partition( arr, left, right, pivotidx );
        _quicksort( arr, left, pivotidx );
        _quicksort( arr, pivotidx+1, right );
    }
}

void
QuickSort::quicksort ()
{
    srand(time(NULL));
    _quicksort( list, 0, len-1 );
}
