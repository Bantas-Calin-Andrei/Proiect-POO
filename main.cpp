#include <iostream>
#include <string>
using namespace std;
#include "Movies.h"
#include "wishlist.h"

int main()
{
    int x = 0;
    Movies filme_vazute;
    wishlist filme_de_vazut;

    while(x != 6) 
    {
        std::cout <<"=============================================="<<"\n";
        std::cout<<"1 - Adaugati film vazut in lista."<<"\n";
        std::cout<<"2 - Afisati lista"<<"\n";
        std::cout<<"3 - Accesez un film."<<"\n";
        std::cout<<"4 - Modificare wishlist"<<"\n";
        std::cout<<"5 - Afisati wishlist"<<"\n";
        std::cout<<"6 - Iesire"<<"\n";
        std::cout <<"=============================================="<<"\n";
        std::cin >> x;
        if(x == 1)
        {
            int var2;
            std::cout<<"1 - Am vazut filmul pentru prima data."<<"\n";
            std::cout<<"2 - Am mai vazut filmul precedent."<<"\n";
            std::cin >> var2;
            std::cin.ignore();
            if(var2 == 1)
            {
                std::string nume;
                std::string age_rating;
                int nrviz;
                int nota;
                std::cout << "Numele filmului: ";
                std::getline(std::cin, nume); 
                std::cout << "Age Rating:  ";
                std::getline(std::cin, age_rating);
                std::cout << "Nota: ";
                std::cin >> nota;
                std::cout << "\n";
                filme_vazute.add_movie(nume,age_rating,nrviz = 1,nota);
            }
            if(var2 == 2)
            {
                std::cout << "Am revizionat filmul: ";
                std::string nume;
                std::getline(std::cin, nume);
                filme_vazute.increment_watched(nume);
            }
        }
        if(x == 2)
        {
            int var2;
            std::cout<<"1 - Dupa nota"<<"\n";
            std::cout<<"2 - Alfabetic"<<"\n";
            std::cin >> var2;
            std::cin.ignore();
            if(var2 == 1)
            {
                filme_vazute.sortare_nota();
                filme_vazute.display_movies();
            }
            if(var2 == 2)
            {
                filme_vazute.sortare_nume();
                filme_vazute.display_movies();
            }
        }
        if(x == 3)
        {
            int var2;
            std::cout << "1 - Schimbare nota film."<<"\n";
            std::cout << "2 - Interogare.(de cate ori am vazut filmul)"<<"\n";
            std::cin >> var2;
            std::cin.ignore();
            if(var2 == 1)
            {
                std::cout << "Numele filmului: ";
                std::string nume_film;
                std::getline(std::cin, nume_film);

                std::cout << "Noua nota: ";
                int nota_film;
                std:: cin >> nota_film;

                filme_vazute.change_rating(nume_film, nota_film);
            }
            if(var2 == 2)
            {
                std::cout << "Numele filmului: ";
                std::string nume_film;
                std::getline(std::cin, nume_film);
                if(!filme_vazute.amvazut(nume_film))
                {
                    int var3;
                    std::cout << "1 - Doriti sa adaugati filmul in wishlist?"<<"\n";
                    std::cout << "2 - Iesire"<<"\n";
                    std::cin >> var3;
                    if(var3 == 1)
                    {
                        std::string rating_film;
                        std::getline(std::cin, rating_film);

                        filme_de_vazut.add_to_wishlist(nume_film,rating_film);
                        std::cout<<"Filmul a fost adaugat cu succes." << "\n";
                    }
                }
            }
        }
        if(x == 4)
        {
            int var2;
            std::cout<<"1 - Adaugare film in wishlist."<<"\n";
            std::cout<<"2 - Schimbare pozitie in wishlist."<<"\n";
            std::cin >> var2;
            std::cin.ignore();
            if(var2 == 1)
            {
                std::cout << "Numele filmului:";
                std::string nume_film;
                std::getline(std::cin, nume_film);
                std::string rating_film;
                std::cout << "Rating film: ";
                std::getline(std::cin, rating_film);
                filme_de_vazut.add_to_wishlist(nume_film,rating_film);
                std::cout<<"Filmul a fost adaugat cu succes." << "\n";
                std::cout<<"Doriti sa plasati filmul pe alta pozitie in wishlist pentru a il vedea mai devreme?" << "\n";
                std::string raspuns;
                std::getline(std::cin, raspuns);
                if(raspuns == "da" || raspuns == "Da" || raspuns == "DA")
                {
                    int pozitie;
                    std::cout<<"Pozitie:";
                    std::cin >> pozitie;
                    filme_de_vazut.schimbare_pozitie(nume_film, pozitie);
                    std::cout<<"Pozitia filmului a fost schimbata."<<"\n";
                }
            }
            if(var2 == 2)
            {
                std::string nume_film;
                int pozitie;
                std::cout<<"Nume film:";
                std::getline(std::cin, nume_film);
                std::cout << "\n";
                std::cout<<"Pozitie:";
                std::cin >> pozitie;
                std::cout << "\n";
                filme_de_vazut.schimbare_pozitie(nume_film, pozitie);
                std::cout<<"Pozitia filmului a fost schimbata."<<"\n";
            }
        }
        if(x == 5)
        {
            filme_de_vazut.display_wishlist();
        }

    }


    return 0;
}