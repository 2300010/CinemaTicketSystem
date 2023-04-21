#include "Schedule.h"

//DEFINITIONS
//Declare getters and setters
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
