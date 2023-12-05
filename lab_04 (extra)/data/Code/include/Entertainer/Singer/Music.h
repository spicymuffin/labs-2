#pragma once
#include <string>

class Music {
   public:
	std::string getMusicName();
	void setMusicName(std::string);
	int getLength();
	void setLength(int, int);

   private:
	std::string _name;
	int _min;
	int _sec;
};