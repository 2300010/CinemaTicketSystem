#include "Movie.h"


//Definition
//Declare constructor and destructor
Movie::Movie(string title, float length, Genre genre, string director, string mainActor, string mainActress)
{
	this->title = title;
	this->length = length;
	this->genre = genre;
	this->director = director;
	this->mainActor = mainActor;
	this->mainActress = mainActress;
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

string Movie::GetMainActress() 
{
	try
	{
		return mainActress;
	}
	catch (...)
	{

	}
}