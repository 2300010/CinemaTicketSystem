#pragma once

#include <string>
#include "MovieList.cpp"

using namespace std;

class Client
{
	//Declare objects
	MovieList watchedMovies;

	//Declare variables for the informations of the client
	string name;
	int age;

public:

	//SIGNATURES
	
	//Declare constructors
	Client(string name, int age);
	Client();
	~Client();

	//Declare getters and setters
	void SetName(string nameOfClient);
	string GetName();
	void SetAge(int ageOfClient);
	int GetAge();
	MovieList GetMoviesWatched();

	//Method that adds a movie to moviesWatched
	void AddWatchedMovies(Movie newWatchedMovie);
};

