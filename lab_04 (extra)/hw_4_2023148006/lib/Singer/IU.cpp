#include "Entertainer/Singer/IU.h"

// implement constructor
IU::IU() : Singer("IU") {}

// implement destructor
IU::~IU() {}

// implement instance getter
IU &IU::instance()
{
    static IU *iu = new IU();
    return *iu;
}