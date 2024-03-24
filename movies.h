#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <string>
#include <vector>
#include "Movie.h"
class Movies
{
private:
    std::vector<class Movie> filme;
public:
    Movies();
    ~Movies();
    void add_movie(std::string name, std::string rating, int count, int nota);
    void increment_watched(std::string name);
    void change_rating(std::string name, int nota_noua);
    bool amvazut(std::string name); // pun la meniu ca daca boolu returneaza 0 daca vreau sa adaug filmul in wishlist
    void sortare_nume();
    void sortare_nota();
    void display_movies();
};

#endif 