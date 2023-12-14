#include "Entertainer/Util/BestArtist.h"
#include "Entertainer/Artist.h"
#include "Entertainer/Entertainers.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
Artist Best::getBestArtist()
{
    if (is_same<T, Actor>::value)
    {
        YihyunCho &yihyun = YihyunCho::instance();
        Suzi &suzi = Suzi::instance();

        Artist a_yihyun = static_cast<Artist>(yihyun);
        Artist a_suzi = static_cast<Artist>(suzi);

        vector<Artist> artistVector = {a_yihyun, a_suzi};

        int maxPopularity = -1;
        int maxPopularityIndex = -1;
        for (int i = 0; i < static_cast<int>(artistVector.size()); i++)
        {
            if (maxPopularity < artistVector[i].getPopularity())
            {
                maxPopularity = artistVector[i].getPopularity();
                maxPopularityIndex = i;
            }
        }
        return artistVector[maxPopularityIndex];
    }
    else if (is_same<T, Singer>::value)
    {
        StayC &stayc = StayC::instance();
        IU &iu = IU::instance();
        BTS &bts = BTS::instance();

        Artist a_stayc = static_cast<Artist>(stayc);
        Artist a_iu = static_cast<Artist>(iu);
        Artist a_bts = static_cast<Artist>(bts);

        vector<Artist> artistVector = {a_stayc, a_iu, a_bts};

        int maxPopularity = -1;
        int maxPopularityIndex = -1;
        for (int i = 0; i < static_cast<int>(artistVector.size()); i++)
        {
            if (maxPopularity < artistVector[i].getPopularity())
            {
                maxPopularity = artistVector[i].getPopularity();
                maxPopularityIndex = i;
            }
        }
        return artistVector[maxPopularityIndex];
    }
    else
    {
        return Artist("UNDEFINED ARTIST: SOMETHING BROKE");
    }
}
