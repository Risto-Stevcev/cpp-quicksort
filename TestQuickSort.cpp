#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include "TestQuickSort.h"


void 
TestQuickSort::setUp ()
{
    int __list[] = {25260, 29649, 54044, 2995, 14108, 15232};
    int __sorted_list[] = {2995, 14108, 15232, 25260, 29649, 54044};

    list_len = sizeof (__list)/sizeof(int);

    list = new int[list_len];
    sorted_list = new int[list_len];

    memcpy( list, __list, sizeof(int)*list_len );
    memcpy( sorted_list, __sorted_list, sizeof(int)*list_len );

    quicksort = new QuickSort( list, list_len );
}

void 
TestQuickSort::tearDown () 
{
    delete quicksort;
    delete[] list;
    delete[] sorted_list;
}

void 
TestQuickSort::testLength ()
{
    CPPUNIT_ASSERT( quicksort->length() == list_len );
}

void 
TestQuickSort::testIndex ()
{
    for (int i = 0; i < list_len; i++) {
      CPPUNIT_ASSERT( list[i] != 0 );
      CPPUNIT_ASSERT( (*quicksort)[i] == list[i] );
    }
}

void
TestQuickSort::testQuicksort ()
{
    int len = quicksort->length();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*quicksort)[i] == list[i] );

    quicksort->quicksort();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*quicksort)[i] == sorted_list[i] );
}


int
main ()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestQuickSort::suite() );
    runner.run();
    return 0;
}
