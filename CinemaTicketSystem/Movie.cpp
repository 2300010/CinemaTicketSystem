#include "Movie.h"


//Definition
//Declare constructor and destructor
Movie::Movie(string title, float length, Genre genre, string director, string mainActor, int rating)
{
	try
	{
		this->title = title;
		this->length = length;
		this->genre = genre;
		this->director = director;
		this->mainActor = mainActor;
	}
	catch (...)
	{

	}
}

Movie::~Movie() 
{

}

//Declare getters
string Movie::GetTitle() 
{
	try
	{
		return title;
	}
	catch (...)
	{

	}
}

float Movie::GetLength() 
{
	try
	{
		return length;
	}
	catch (...)
	{

	}
}

Genre Movie::GetGenre()
{
	try
	{
		return genre;
	}
	catch (...)
	{

	}
}

string Movie::GetDirector() 
{
	try
	{
		return director;
	}
	catch (...)
	{

	}
}

string Movie::GetMainActor() 
{
	try
	{
		return mainActor;
	}
	catch (...)
	{

	}
}

int Movie::GetRating() 
{
	try
	{
		return rating;
	}
	catch (...)
	{

	}
}

string Movie::toString() {
	try
	{
		return "Movie : " + title + ", length: " + to_string(length) + ", " + " genre : " + to_string(genre) + ", " + "Actor : " + mainActor + ", rating out of 10 : "+ to_string(rating);  
	}
	catch (...)
	{

	}
}