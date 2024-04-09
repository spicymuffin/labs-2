#pragma once
#include <string>

#include "Entertainer/MBTI.h"

class Artist {
   public:
	Artist(std::string name) : _name(name), _mbti(MBTI::NONE) {}
	virtual ~Artist() {}

	std::string getName();
	void setName(std::string);
	MBTI getMBTI();
	void setMBTI(MBTI);
	int getPopularity();
	void setPopularity(int);

	virtual std::string getJobName() { return "Artist"; }

   private:
	std::string _name;
	MBTI _mbti;
	int _popularity;
};