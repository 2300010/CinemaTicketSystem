#include "Client.h"

//DEFINITIONS

//Declare constructors
Client::Client(string name, int age) 
{
	this->name = name;
	this->age = age;
}

Client::Client(){}

Client::~Client(){}
 
//Declare getters and setters
void Client::SetName(string nameOfClient) 
{
	try
	{
		name = nameOfClient;
	}
	catch (...)
	{

	}
}

string Client::GetName() 
{
	try
	{
		return name;
	}
	catch (...)
	{

	}
}

void Client::SetAge(int ageOfClient) 
{
	try
	{
		age = ageOfClient;
	}
	catch (...)
	{

	}
}

int Client::GetAge() 
{
	try
	{
		return age;
	}
	catch (...)
	{

	}
}

MovieList Client::GetMoviesWatched()
{
	return watchedMovies;
}

//Method that adds a movie to moviesWatched
void Client::AddWatchedMovies(Movie newWatchedMovie) 
{
	watchedMovies.insertAtBeginning(newWatchedMovie);
}