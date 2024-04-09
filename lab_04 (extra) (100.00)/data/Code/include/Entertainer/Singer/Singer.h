#pragma once
#include <string>

#include "Entertainer/Artist.h"
#include "Entertainer/Singer/Music.h"

class Singer : public Artist {
   public:
	Singer(std::string);
	virtual ~Singer();

	Music getFavoriteSong();
	void setFavoriteSong(Music);
	std::string getJobName() override;

   private:
	Music _favoriteSong;
};