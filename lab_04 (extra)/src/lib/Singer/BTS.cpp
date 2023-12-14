#include "Entertainer/Singer/BTS.h"

BTS &BTS::instance()
{
    static BTS *bts = new BTS();
    return *bts;
}

