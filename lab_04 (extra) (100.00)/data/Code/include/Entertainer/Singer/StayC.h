#pragma once
#include <string>
#include <vector>

#include "Entertainer/Singer/Music.h"
#include "Entertainer/Singer/Singer.h"

class Group : public Artist {
   public:
	Group(std::string);
	virtual ~Group();

	std::vector<Singer> getMembers();
	void setMembers(std::vector<Singer>);
	std::string getName();
	int getPopularity();
	void setPopularity(int);
	std::string getJobName() override;

   private:
	std::vector<Singer> _members;
};

class StayC : public Group {
   public:
	// Singleton : [https://ko.wikipedia.org/wiki/싱글턴_패턴]
	static StayC& instance();

	StayC();
	~StayC();

	std::vector<Music> getMusic();
	void setMusic(std::vector<Music>);
	std::string getLightStick();
	void setLightStick(std::string);

   private:
	std::vector<Music> _music;
	std::string _lightStick;
};
