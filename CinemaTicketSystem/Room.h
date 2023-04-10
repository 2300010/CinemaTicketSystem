#pragma once
#include "MovieList.h"
#include "ERoomType.h"

class Room
{
	//Declare variables for the information of the room
	int idNumber;
	int seatsAmount;
	double ticketPrice;
	//MovieList
	ERoomType roomType;

public:

	//SIGNATURES
	//Declare constructor and destructor
	Room();
	~Room();

	//Declare getters and setters
	int GetIdNumber();
	int GetSeatsAmount();
	double GetTicketPrice();
	void SetTicketPrice(double newPrice);
	ERoomType GetRoomType();
};

