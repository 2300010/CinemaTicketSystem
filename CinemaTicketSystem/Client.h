#pragma once
#include <string>
#include "MovieList.h"

using namespace std;

class Client
{
	//Declare objects
	MovieList moviesWatched;

	//Declare variables for the informations of the client
	string name;
	int age;

public:

	//SIGNATURES
	//Declare getters and setters
	void SetName(string nameOfClient);
	string GetName();
	void SetAge(int ageOfClient);
	int GetAge();
};

