#include "Entertainer/Actor/Yihyun.h"

#include <string>

using namespace std;

YihyunCho::YihyunCho() : Actor("Yihyun") {}

YihyunCho::~YihyunCho() {}

YihyunCho &YihyunCho::instance()
{
    static YihyunCho *yihyuncho = new YihyunCho();
    return *yihyuncho;
}

Drama *YihyunCho::getDramaList(int *numDrama)
{
    *numDrama = _numDrama;
    return _drama;
}

void YihyunCho::setDramaList(int numDrama, Drama *drama)
{
    _numDrama = numDrama;
    _drama = drama;
}