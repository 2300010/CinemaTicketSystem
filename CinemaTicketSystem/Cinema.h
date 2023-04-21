#pragma once
#include "MovieList.h"
#include "Room.h"
#include "Schedule.h"

//Declare struct for the room binary tree
struct RoomNode
{
	int roomId;
	RoomNode* left;
	RoomNode* right;
};

class Cinema
{
	//Declare objects
	MovieList availableMovies;
	Schedule specificSchedule;

	//Declare variables for the cinema characteristics
	int roomAmount = 0;

	//Declare array of movies' schedules
	Schedule movieSchedules[];

public:

	//SIGNATURES
	//Declare constructor and destructor
	Cinema(int roomAmount);
	~Cinema();

	//Declare getters and setters
	int GetRoomAmount();
	void SetRoomAmount(int newAmount);

	//Methode that generates a schedule for every movie
	void GenerateSchedule();

	//Method that creates a RoomNode
	RoomNode* CreateRoomNode(int roomId);

	//Method that add a RoomNode to binary tree
	RoomNode* AddRoomNode(RoomNode* roomsRoot, int roomId);

	//Method that finds a RoomNode
	RoomNode* SearchRoomNode(RoomNode* roomsRoot, int roomId);
};

