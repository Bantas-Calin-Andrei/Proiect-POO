#include <iostream>
#include <vector>
#include <string>
#include "wishlist.h"

wishlist::wishlist(){}
wishlist::~wishlist(){}

void wishlist::add_to_wishlist(std::string name, std::string rating)
{
    bool already = false;
    int n = this->devazut.size();
    for(int i=0; i<n; i++)
        if(this->devazut[i].name == name)
            already = true;
    if(already == true)
        std::cout << "Deja este in wishlist." << std::endl;
    else
    {
        Movie movie{name,rating};
        this->devazut.push_back(movie); // trebuie afisat fara nota ca nu am vazut inca filmul
    }
}
void wishlist::display_wishlist()
{
    int n = this->devazut.size();
    for(int i=0; i<n; i++)
    {
        std::cout << this->devazut[i].name;
        std::cout << "\n";
    }
    std::cout << "-------------------------";
    std::cout << "\n";
}
void wishlist::schimbare_pozitie(std::string name, int pozitie)
{
    Movie temporar;
    int n = this->devazut.size();
    for(int i=0; i<n; i++)
    {
        if(this->devazut[i].name == name)
        {
            temporar = devazut[i];
            devazut.erase (devazut.begin()+i);
            devazut.insert(devazut.begin() + pozitie - 1,temporar);
            return;
        }
    }
}

