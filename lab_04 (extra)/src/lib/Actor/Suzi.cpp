#include "Entertainer/Actor/Suzi.h"

// implement constructor
Suzi::Suzi() : Actor("Suzi") {}

// implement destructor
Suzi::~Suzi() {}

// implement instance getter
Suzi &Suzi::instance()
{
    static Suzi *suzi = new Suzi();
    return *suzi;
}
