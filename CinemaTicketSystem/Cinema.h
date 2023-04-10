#pragma once
#include "MovieList.h"
#include "Room.h"
#include "Schedule.h"

class Cinema
{
	//Declare objects
	MovieList availableMovies;
	Schedule specificSchedule;

	//Declare variables for the cinema characteristics
	int roomAmount;

	//Declare array of rooms of the cinema
	Room cinemaRooms[];

public:

	//SIGNATURES
	//Declare constructor and destructor
	Cinema(int roomAmount);
	~Cinema();

	//Declare getters and setters
	int GetRoomAmount();
	void SetRoomAmount();

	//Methode that generates a schedule for every movie
	void GenerateSchedule();
};
