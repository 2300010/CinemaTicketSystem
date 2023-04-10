#pragma once
#include <string>
#include "EGenre.h"

using namespace std;

class Movie
{
	//Declare variables for the informations of the movie
	string title;
	float length;
	Genre genre;
	string director;
	string mainActor;
	string mainActress;

public:

	//SIGNATURES
	//Declare constructor and destructor
	Movie(string title, float length, Genre genre, string director, string mainActor, string mainActress);
	~Movie();

	//Declare getters
	string GetTitle();
	float GetLength();
	Genre GetGenre();
	string GetDirector();
	string GetMainActor();
	string GetMainActress();
};

