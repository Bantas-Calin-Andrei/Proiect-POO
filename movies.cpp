#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Movies.h"

Movies::Movies(){}
Movies::~Movies(){}

void Movies::add_movie(std::string name, std::string rating, int count, int nota)
{
    bool already = false;
    int n = this->filme.size();
    for(int i=0; i<n; i++)
        if(this->filme[i].name == name)
            already = true;
    if(already == true)
        std::cout << "Film deja adugat" << "\n";
    else
    {
        Movie movie{name,rating,count,nota};
        this->filme.push_back(movie);
        std::cout << "Film adaugat cu succes." << "\n";
    }
}

void Movies::increment_watched(std::string name)
{
    int n = this->filme.size();
    for(int i=0; i<n; i++)
    {
        if(this->filme[i].name == name)
        {
            this->filme[i].count++;
            std::cout << "Filmul a fost incrementat." << "\n";
            return;
        }

    }
    std::cout << "Numele nu a fost gasit" << std::endl;
}

void Movies::change_rating(std::string name, int nota_noua)
{
    int n = this->filme.size();
    for(int i = 0; i < n; i++)
    {
        if(this->filme[i].name == name)
        {
            this->filme[i].nota = nota_noua;
            std::cout << "Nota s-a schimbat cu succes." << "\n";
            return;
        }
    }
    std::cout << "Numele nu a fost gasit" << std::endl;
}

bool Movies::amvazut(std::string name)
{
    int n = this->filme.size();
    for(int i = 0; i < n; i++)
    {
        if(this->filme[i].name == name)
        {
            std::cout << "Ai vazut filmul " << name << " de " << filme[i].count << " ori." << "\n";
            return 1;
        }
        std::cout << "Nu am vazut " << name << "inca.";
        return 0;
    }
    
}

void Movies::display_movies()
{
    std::cout << "--------------------------" << "\n";
    int n = this->filme.size();
    for(int i=0; i < n; i++)
    {
        std::cout << this->filme[i].name << " " << "Nota " << this->filme[i].nota << " ";
        std::cout << "\n";
    }
    std::cout << "--------------------------";
    std::cout << std::endl;
}

void Movies::sortare_nota()
{
    std::sort(filme.begin( ), filme.end( ), []( const Movie& a, const Movie& b)
    {
        return a.nota < b.nota;
    });
}

void Movies::sortare_nume()
{
    std::sort(filme.begin( ), filme.end( ), []( const Movie& a, const Movie& b)
    {
        return a.name < b.name; // nu inteleg de ce sorteaza invers
    });
}