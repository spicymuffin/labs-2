#include "Entertainer/Actor/Yihyun.h"

#include <string>

using namespace std;

// implement constructor
YihyunCho::YihyunCho() : Actor("Yihyun") {}

// implement destructor
YihyunCho::~YihyunCho() {}

// implement instance getter
YihyunCho &YihyunCho::instance()
{
    static YihyunCho *yihyuncho = new YihyunCho();
    return *yihyuncho;
}

// implement getDramaList
Drama *YihyunCho::getDramaList(int *numDrama)
{
    *numDrama = _numDrama;
    return _drama;
}

// implement setDramaList
void YihyunCho::setDramaList(int numDrama, Drama *drama)
{
    _numDrama = numDrama;
    _drama = drama;
}