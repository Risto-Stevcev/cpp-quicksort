#ifndef __TESTMERGESORT_H__
#define __TESTMERGESORT_H__
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "QuickSort.h"

using namespace std;


class TestQuickSort : public CppUnit::TestFixture
{
    public:

    void setUp();
    void tearDown();
    void testLength();
    void testIndex();
    void testQuick();
    void testQuicksort();

    static 
    CppUnit::Test *suite ()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestQuickSort" );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestQuickSort>( 
                                       "testLength", 
                                       &TestQuickSort::testLength ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestQuickSort>( 
                                       "testIndex", 
                                       &TestQuickSort::testIndex ) );
        //suiteOfTests->addTest( new CppUnit::TestCaller<TestQuickSort>( 
        //                               "testQuick", 
        //                               &TestQuickSort::testQuick ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestQuickSort>( 
                                       "testQuicksort", 
                                       &TestQuickSort::testQuicksort ) );
        return suiteOfTests;
    }


    private:

    QuickSort *quicksort;
    int *list;
    int *sorted_list;
    int list_len;
};
#endif
