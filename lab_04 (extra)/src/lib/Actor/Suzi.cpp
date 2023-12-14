#include "Entertainer/Actor/Suzi.h"

Suzi &Suzi::instance()
{
    static Suzi *suzi = new Suzi();
    return *suzi;
}
