#include "Movie.h"
#include <iostream>
#include <string>

Movie::Movie(std::string name_val, std::string rating_val, int count_val, int nota_val) 
    : name{name_val}, rating{rating_val}, count{count_val}, nota{nota_val}
{}

Movie::Movie(const Movie &object) : Movie{object.name, object.rating, object.count, object.nota}
{}

Movie::~Movie() {}

Movie Movie::operator=(const Movie &object)
{
    if(this == &object)
        return *this;
    else
    {
        this->nota = object.nota;
        this->name = object.name;
        this->count = object.count;
        this->rating = object.rating;
    }

    return *this;
}
