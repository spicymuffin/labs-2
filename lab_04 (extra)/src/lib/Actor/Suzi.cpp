#include "Entertainer/Actor/Suzi.h"

Suzi::Suzi() : Actor("Suzi") {}

Suzi::~Suzi() {}

Suzi &Suzi::instance()
{
    static Suzi *suzi = new Suzi();
    return *suzi;
}
