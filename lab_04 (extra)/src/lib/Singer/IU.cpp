#include "Entertainer/Singer/IU.h"

IU &IU::instance()
{
    static IU *iu = new IU();
    return *iu;
}