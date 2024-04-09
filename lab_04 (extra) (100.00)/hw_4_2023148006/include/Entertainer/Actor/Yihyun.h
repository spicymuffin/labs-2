#pragma once
#include <string>

#include "Entertainer/Actor/Actor.h"
#include "Entertainer/Actor/Drama.h"

class YihyunCho : public Actor {
   public:
	// Singleton : [https://ko.wikipedia.org/wiki/싱글턴_패턴]
	static YihyunCho& instance();

	~YihyunCho();

	Drama* getDramaList(int*);
	void setDramaList(int, Drama*);

   private:
	YihyunCho();
	Drama* _drama;
	int _numDrama;
};