#include "Client.h"

//DEFINITIONS
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