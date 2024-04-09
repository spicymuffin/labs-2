#include <cassert>
#include <iostream>

#include "./lib/Util/BestArtist.cpp"
#include "Entertainer/Entertainers.h"
#include "Entertainer/MBTI.h"
#include "Entertainer/Util/BestArtist.h"

int main() {
	std::cout << ">>>>>>>>>>  CHECK  <<<<<<<<<<" << std::endl;

	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////

	std::cout << "======= Test Actor Initialization" << std::endl;

	YihyunCho& yihyun = YihyunCho::instance();
	Suzi& suzi = Suzi::instance();

	yihyun.setMBTI(MBTI::ISFP);
	yihyun.setPopularity(100);
	suzi.setMBTI(MBTI::INFP);
	suzi.setPopularity(50);

	assert(yihyun.getName() == "Yihyun");
	assert(suzi.getName() == "Suzi");
	assert(yihyun.getJobName() == "Actor");
	assert(yihyun.getMBTI() == MBTI::ISFP);
	assert(suzi.getMBTI() == MBTI::INFP);
	assert(yihyun.getPopularity() == 100);
	assert(suzi.getPopularity() == 50);

	Drama drama;
	drama.setName("Architecture 101");
	drama.setNumSeries(1);
	suzi.setMasterpiece(drama);
	assert(suzi.getMasterpiece().getName() == "Architecture 101");
	assert(suzi.getMasterpiece().getNumSeries() == 1);

	Drama* dramaList = new Drama[2];
	dramaList[0].setName("All of Us Are Dead 2");
	dramaList[0].setNumSeries(2);
	dramaList[1].setName("Hospital Playlist");
	dramaList[1].setNumSeries(2);
	yihyun.setDramaList(2, dramaList);

	int numDrama = 0;
	Drama* dramaList2 = yihyun.getDramaList(&numDrama);
	assert(numDrama == 2);
	assert(dramaList2[1].getName() == "Hospital Playlist");
	assert(dramaList2[1].getNumSeries() == 2);

	std::cout << "======= Test Actor Initialization --- OK" << std::endl;

	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////

	std::cout << "======= Test Singer Initialization" << std::endl;

	StayC& stayc = StayC::instance();
	IU& iu = IU::instance();
	BTS& bts = BTS::instance();

	assert(stayc.getJobName() == "GroupSinger");
	assert(iu.getJobName() == "Singer");
	assert(bts.getJobName() == "Singer");

	assert(stayc.getName() == "StayC");
	assert(iu.getName() == "IU");
	assert(bts.getName() == "BTS");

	Music music;
	music.setMusicName("Celebrity");
	music.setLength(3, 15);

	iu.setFavoriteSong(music);
	assert(iu.getFavoriteSong().getMusicName() == "Celebrity");
	assert(iu.getFavoriteSong().getLength() == 3 * 60 + 15);

	stayc.setPopularity(3000);
	iu.setPopularity(500);
	bts.setPopularity(550);

	assert(stayc.getPopularity() == 3000);
	assert(iu.getPopularity() == 500);
	assert(bts.getPopularity() == 550);

	std::vector<Singer> members;
	members.push_back(Singer("sumin"));
	members.push_back(Singer("sieun"));
	members.push_back(Singer("isa"));
	members.push_back(Singer("seeun"));
	members.push_back(Singer("yoon"));
	members.push_back(Singer("j"));

	stayc.setMembers(members);
	stayc.setLightStick("wink stick");

	assert(stayc.getMembers().size() == 6);
	assert(stayc.getMembers()[0].getName() == "sumin");
	assert(stayc.getLightStick() == "wink stick");

	std::vector<Music> music_;
	music_.push_back(Music());
	music_.push_back(Music());
	music_.push_back(Music());
	Music mm;
	mm.setMusicName("teddy bear");
	music_.push_back(mm);

	stayc.setMusic(music_);
	assert(stayc.getMusic().size() == 4);
	assert(stayc.getMusic().back().getMusicName() == "teddy bear");

	std::cout << "======= Test Singer Initialization --- OK" << std::endl;

	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////

	std::cout << "======= Test Singleton" << std::endl;

	YihyunCho& yihyun2 = YihyunCho::instance();
	IU& iu2 = IU::instance();

	assert(yihyun2.getPopularity() == 100);
	assert(iu2.getFavoriteSong().getMusicName() == "Celebrity");

	std::cout << "======= Test Singleton --- OK" << std::endl;

	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////

	std::cout << "======= Test BestArtist Template Function" << std::endl;

	Artist bestActor = Best::getBestArtist<Actor>();
	assert(bestActor.getMBTI() == MBTI::ISFP);

	Artist bestSinger = Best::getBestArtist<Singer>();
	assert(bestSinger.getPopularity() == 3000);

	std::cout << "======= Test BestArtist Template Function --- OK" << std::endl;

	return 0;
}
