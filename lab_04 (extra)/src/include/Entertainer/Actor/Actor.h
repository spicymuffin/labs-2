#pragma once
#include <string>

#include "Entertainer/Actor/Drama.h"
#include "Entertainer/Artist.h"

class Actor : public Artist {
   public:
	Actor(std::string);
	virtual ~Actor();

	Drama getMasterpiece();
	void setMasterpiece(Drama);
	std::string getJobName() override;

   private:
	Drama _masterpiece;
};