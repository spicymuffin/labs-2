#pragma once
#include "Entertainer/Singer/Singer.h"

class BTS : public Singer {
   public:
	// Singleton : [https://ko.wikipedia.org/wiki/싱글턴_패턴]
	static BTS& instance();

	BTS();
	~BTS();
};