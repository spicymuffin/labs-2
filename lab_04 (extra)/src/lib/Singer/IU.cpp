#include "Entertainer/Singer/IU.h"

IU::IU() : Singer("IU") {}

IU::~IU() {}

IU &IU::instance()
{
    static IU *iu = new IU();
    return *iu;
}