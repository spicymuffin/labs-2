#pragma once
#include <string>

class Drama {
   public:
	std::string getName();
	void setName(std::string);
	int getNumSeries();
	void setNumSeries(int);
	Drama& operator=(Drama);

   private:
	std::string _name;
	int _numSeries;
};