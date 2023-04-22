#pragma once
#include <string>
#include "EGenre.h"
#include <cstddef>

using namespace std;

class Movie
{
	//Declare variables for the informations of the movie
	string title;
	float length;
	Genre genre;
	string director;
	string mainActor;
	int rating;

	

public:
	// Linked List node 
	Movie* next;

	//SIGNATURES
	//Declare constructor and destructor

	Movie(string title, float length, Genre genre, string director, string mainActor, int rating);
	~Movie();
	// Linked List node 
	//Movie* next;				EN DOUBLE! SA
	//Declare getters
	string GetTitle();
	float GetLength();
	Genre GetGenre();
	string GetDirector();
	string GetMainActor();
	int GetRating();
	string toString();
};

