#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include "Movies.h"
class Movie
{
private:
    friend class Movies;
    friend class wishlist;
    std::string name;
    std::string rating;
    int nota;
    int count;
public:
    Movie(std::string name = "None", std::string rating = "None", int count = 0, int nota = 0);
    ~Movie();
    Movie(const Movie &object);
    Movie operator=(const Movie &object);
};
#endif 