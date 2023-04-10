#include "Room.h"

//DEFINITIONS
//Declare constructor and destructor
Room::Room() 
{

}
Room::~Room()
{

}

//Declare getters and setters
int Room::GetIdNumber() 
{
	try
	{
		return idNumber;
	}
	catch (...)
	{

	}
}

int Room::GetSeatsAmount() 
{
	try
	{
		return seatsAmount;
	}
	catch (...)
	{

	}
}

double Room::GetTicketPrice() 
{
	try
	{
		return ticketPrice;
	}
	catch (...)
	{

	}
}

void Room::SetTicketPrice(double newPrice) 
{
	try
	{
		ticketPrice = newPrice;
	}
	catch (...)
	{

	}
}

ERoomType Room::GetRoomType() 
{
	try
	{
		return roomType;
	}
	catch (...)
	{

	}
}
