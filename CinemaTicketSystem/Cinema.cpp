#include "Cinema.h"

//DEFINITIONS
//Declare constructor and destructor
Cinema::Cinema(int roomAmount) 
{
	try
	{
		this->roomAmount = roomAmount;
	}
	catch (...)
	{

	}
}

Cinema::~Cinema() 
{

}

//Declare getters and setters
int Cinema::GetRoomAmount() 
{
	try
	{
		return roomAmount;
	}
	catch (...)
	{

	}
}

void Cinema::SetRoomAmount(int newAmount) 
{
	try
	{
		roomAmount = newAmount;
	}
	catch (...)
	{

	}
}

//Methode that generates a schedule for every movie
void Cinema::GenerateSchedule() 
{

}