#include "Entertainer/Singer/BTS.h"

BTS::BTS() : Singer("BTS") {}

BTS::~BTS() {}

BTS &BTS::instance()
{
    static BTS *bts = new BTS();
    return *bts;
}
