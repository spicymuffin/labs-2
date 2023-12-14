#include "Entertainer/Util/BestArtist.h"
#include "Entertainer/Artist.h"
#include "Entertainer/Entertainers.h"

#include <vector>
#include <string>

using namespace std;

// implement getBtstArtist
template <typename T>
Artist Best::getBestArtist()
{
    // if is Actor
    if (is_same<T, Actor>::value)
    {
        // get singletons
        YihyunCho &yihyun = YihyunCho::instance();
        Suzi &suzi = Suzi::instance();

        // cast them to Artists
        Artist a_yihyun = static_cast<Artist>(yihyun);
        Artist a_suzi = static_cast<Artist>(suzi);

        // put them in a vector
        vector<Artist> artistVector = {a_yihyun, a_suzi};

        // figure our most popular
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
        // return the most popular
        return artistVector[maxPopularityIndex];
    }
    // if is Singer
    else if (is_same<T, Singer>::value)
    {
        // get singletons
        StayC &stayc = StayC::instance();
        IU &iu = IU::instance();
        BTS &bts = BTS::instance();

        // cast them to Artists
        Artist a_stayc = static_cast<Artist>(stayc);
        Artist a_iu = static_cast<Artist>(iu);
        Artist a_bts = static_cast<Artist>(bts);

        // put them in a vector
        vector<Artist> artistVector = {a_stayc, a_iu, a_bts};

        // figure our most popular
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
        // return the most popular
        return artistVector[maxPopularityIndex];
    }
    // else something went wrong, but its a miracle we didn't crash
    else
    {
        return Artist("UNDEFINED ARTIST: SOMETHING BROKE");
    }
}
