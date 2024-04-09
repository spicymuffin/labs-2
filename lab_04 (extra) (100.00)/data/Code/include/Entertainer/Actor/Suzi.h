#pragma once
#include "Entertainer/Actor/Actor.h"

class Suzi : public Actor {
   public:
	// Singleton : [https://ko.wikipedia.org/wiki/싱글턴_패턴]
	static Suzi& instance();

	~Suzi();

   private:
	Suzi();
};