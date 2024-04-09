#include <iostream>
#include <cstdlib>
#include <string>

#include "util.h"

using namespace std;

template <class T>
class Pair
{
public:
    Pair();
    Pair(T firstVal, T secondVal)
    {
        first = firstVal;
        second = secondVal;
    }
    void setFirst(T newVal)
    {
        first = newVal;
    }
    void setSecond(T newVal)
    {
        second = newVal;
    }
    const T getFirst() const
    {
        return first;
    }
    const T getSecond() const
    {
        return second;
    }
    void printPair() const
    {
        cout << first << " " << second << endl;
    }

private:
    T first;
    T second;
};
