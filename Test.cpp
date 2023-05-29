#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <typeinfo> // For typeid(...)
#include <sstream>

#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("constractors do not throw")
{
    CHECK_NOTHROW(MagicalContainer mc);
    MagicalContainer mc;
    CHECK_NOTHROW(MagicalContainer:: AscendingIterator ascIter(mc));
    CHECK_NOTHROW(MagicalContainer:: SideCrossIterator crossIter(mc));
    CHECK_NOTHROW(MagicalContainer:: PrimeIterator primeIter(mc));
}

TEST_CASE("MagicalContainer")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    CHECK(mc.size()==5);
    mc.removeElement(5);
    CHECK(mc.size()==4);
    mc.removeElement(4);
    mc.removeElement(3);
    mc.removeElement(2);
    mc.removeElement(1);
    CHECK(mc.size()==0);
    CHECK_THROWS(mc.removeElement(0));
    
   
}

TEST_CASE("AscendingIterator operators")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer mc2;

    MagicalContainer:: AscendingIterator ascIter1(mc);//12345
    MagicalContainer:: AscendingIterator ascIter2(mc2);
  
    //Using operators on iterators of differant type or differant containers should throw an exaption. 
  
    bool exceptionThrown = false;
    try {
        bool result = (ascIter1 > ascIter2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (ascIter1<ascIter2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (ascIter1==ascIter2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (ascIter1!=ascIter2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    // == , != ,  > , <
     MagicalContainer:: AscendingIterator ascIter3(mc);
    
    ++ ascIter3;
    CHECK(ascIter3>ascIter1);
    CHECK(ascIter1<ascIter3);
    CHECK(ascIter3!=ascIter1);
    ++ascIter1;
    CHECK(ascIter3==ascIter1);

    // ++
    for (int i = 0; i < 3; i++)
    {
        ++ascIter1;
    }
    CHECK_THROWS(++ascIter1);

    // * , beggin() , end()
    CHECK(*(ascIter3.begin())==2);
    CHECK(*(ascIter3.end())==5);

    
}

TEST_CASE("SideCrossIterator operators")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer mc2;

    MagicalContainer:: SideCrossIterator sc1(mc);//15243
    MagicalContainer:: SideCrossIterator sc2(mc2);

    //Using operators on iterators of differant type or differant containers should throw an exaption. 
        bool exceptionThrown = false;
    try {
        bool result = (sc1 > sc2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (sc1<sc2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (sc1==sc2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (sc1!=sc2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    
    // == , != ,  > , <
    MagicalContainer:: SideCrossIterator sc3(mc);
    
    ++sc3;
    CHECK(sc3>sc1);
    CHECK(sc1<sc3);
    CHECK(sc3!=sc1);
    ++sc1;
    CHECK(sc3==sc1);

    // ++
    for (int i = 0; i < 3; i++)
    {
        ++sc1;
    }
    CHECK_THROWS(++sc1);

    // * , beggin() , end()
    CHECK(*(sc3.begin())==5);
    CHECK(*(sc3.end())==3);

        
}

TEST_CASE("PrimeIterator operators")
{
    MagicalContainer mc;
    mc.addElement(1);
    mc.addElement(2);
    mc.addElement(3);
    mc.addElement(4);
    mc.addElement(5);

    MagicalContainer mc2;

    MagicalContainer:: PrimeIterator pi1(mc);//1235
    MagicalContainer:: PrimeIterator pi2(mc2);

    //Using operators on iterators of differant type or differant containers should throw an exaption. 
        bool exceptionThrown = false;
    try {
        bool result = (pi1 > pi2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (pi1<pi2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (pi1==pi2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    exceptionThrown = false;

    try {
        bool result = (pi1!=pi2);
        // The above line should throw an exception
    } catch (const std::exception& ex) {
        // Exception is thrown as expected
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

    // == , != ,  > , <
    MagicalContainer:: PrimeIterator pi3(mc);
    
    ++pi3;
    CHECK(pi3>pi1);
    CHECK(pi1<pi3);
    CHECK(pi3!=pi1);
    ++pi1;
    CHECK(pi3==pi1);

    // ++
    for (int i = 0; i < 2; i++)
    {
        ++pi1;
    }
    CHECK_THROWS(++pi1);

    // * , beggin() , end()
    CHECK(*(pi3.begin())==2);
    CHECK(*(pi3.end())==5);

    
}
