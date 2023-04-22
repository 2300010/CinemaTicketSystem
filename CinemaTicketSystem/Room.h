#pragma once
#include "MovieList.cpp"
#include "ERoomType.h"

struct Room
{
	//Declare variables for the information of the room
	int idNumber = 0;
	int seatsAmount = 0;
	double ticketPrice = 0;
	ERoomType roomType = Regular;

public:

	//SIGNATURES
	//Declare constructor and destructor
	Room(int idNumber, int seatsAmount, double ticketPrice, ERoomType roomType);
	~Room();

	//Declare getters and setters
	int GetIdNumber();
	int GetSeatsAmount();
	double GetTicketPrice();
	void SetTicketPrice(double newPrice);
	ERoomType GetRoomType();
};

