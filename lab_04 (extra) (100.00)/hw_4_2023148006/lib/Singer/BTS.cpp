#include "Entertainer/Singer/BTS.h"

// implement constructor
BTS::BTS() : Singer("BTS") {}

// implement destructor
BTS::~BTS() {}

// implement instance getter
BTS &BTS::instance()
{
    static BTS *bts = new BTS();
    return *bts;
}
