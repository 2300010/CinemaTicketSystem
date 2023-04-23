#include "Schedule.h"

//DEFINITIONS
//Declare constructor
Schedule::Schedule(Movie* scheduledMovie, float startingTime, float endingTime, int roomId) 
{
	this->scheduledMovie = scheduledMovie;
	this->startingTime = startingTime;
	this->endingTime = endingTime;
	this->roomId = roomId;
}

//Declare getters and setters
Movie* Schedule::GetScheduledMovie() 
{
	try
	{
		return scheduledMovie;
	}
	catch (...)
	{

	}
}

void Schedule::SetScheduledMovie(Movie* scheduledMovie) 
{
	try
	{
		this->scheduledMovie = scheduledMovie;
	}
	catch (...)
	{

	}
}

float Schedule::GetStartingTime() 
{
	try
	{
		return startingTime;
	}
	catch (...)
	{

	}
}

void Schedule::SetStartingTime(float movieStartTime)
{
	try
	{
		startingTime = movieStartTime;
	}
	catch (...)
	{

	}
}

float Schedule::GetEndingTime() 
{
	try
	{
		return endingTime;
	}
	catch (...)
	{

	}
}

void Schedule::SetEndingTime(float movieEndTime)
{
	try
	{
		endingTime = movieEndTime;
	}
	catch (...)
	{

	}
}

int Schedule::GetRoomId() 
{
	try
	{
		return roomId;
	}
	catch (...)
	{

	}
}

void Schedule::SetRoomId(int idOfChosenRoom)
{
	try
	{
		roomId = idOfChosenRoom;
	}
	catch (...)
	{

	}
}
