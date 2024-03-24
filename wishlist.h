#ifndef _WISHLIST_H_
#define _WISHLIST_H_
#include <string>
#include <vector>
#include "Movie.h"

class wishlist
{
    private:
        std::vector<class Movie> devazut;

    public:
        wishlist();
        ~wishlist();
        void add_to_wishlist(std::string name, std::string rating);
        void display_wishlist();
        void schimbare_pozitie(std::string name, int pozitie);
};

#endif 