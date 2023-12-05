#pragma once
#include "Entertainer/Actor/Actor.h"
#include "Entertainer/Artist.h"
#include "Entertainer/Singer/Singer.h"

namespace Best {

// If getBestArtist<Singer>(), then return the singer with the highest popularity.
// If getBestArtist<Actor>(), then return the actor with the highest popularity.
// Return type is Artist which is the parent class of singer and actor.
template <typename T>
Artist getBestArtist();

};