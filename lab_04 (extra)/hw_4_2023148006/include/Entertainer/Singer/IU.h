#pragma once
#include "Entertainer/Singer/Singer.h"

class IU : public Singer {
   public:
	// Singleton : [https://ko.wikipedia.org/wiki/싱글턴_패턴]
	static IU& instance();

	IU();
	~IU();
};