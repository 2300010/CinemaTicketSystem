#include "Room.h"

//DEFINITIONS
//Declare constructor and destructor
Room::Room(int idNumber, int seatsAmount, double ticketPrice, ERoomType roomType)
{
	this->idNumber = idNumber;
	this->seatsAmount = seatsAmount;
	this->ticketPrice = ticketPrice;
	this->roomType = roomType;
}

Room::~Room()
{

}

//Declare getters and setters
int Room::GetIdNumber() 
{
	try
	{
		return this->idNumber;
	}
	catch (...)
	{

	}
}

int Room::GetSeatsAmount() 
{
	try
	{
		return this->seatsAmount;
	}
	catch (...)
	{

	}
}

double Room::GetTicketPrice() 
{
	try
	{
		return this->ticketPrice;
	}
	catch (...)
	{

	}
}

void Room::SetTicketPrice(double newPrice) 
{
	try
	{
		this->ticketPrice = newPrice;
	}
	catch (...)
	{

	}
}

ERoomType Room::GetRoomType() 
{
	try
	{
		return this->roomType;
	}
	catch (...)
	{

	}
}
