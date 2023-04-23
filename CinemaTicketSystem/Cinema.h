#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "Room.h"
#include "Schedule.h"
#include "MovieList.cpp"

using namespace std;

class Cinema
{
	//Declare struct for the room binary tree
	struct RoomNode
	{
		Room room;
		RoomNode* left;
		RoomNode* right;

		//Declare constructor for RoomNode struct
		RoomNode(Room newRoom, RoomNode* newLeft, RoomNode* newRight) :
			room(newRoom), left(newLeft), right(newRight) {};
	};

	//Declare constants for opening hours
	const int OPENING_TIME = 12;
	const int CLOSING_TIME = 24;

	//Declare objects
	MovieList availableMovies;

	//Declare variables for the cinema characteristics
	int roomAmount = 0;
	RoomNode* root = nullptr;

	//Declare vector to receive the schedule of every projections
	vector<Schedule> cinemaSchedule;

	//Declare vector to receive all the rooms at creation
	vector<Room> cinemaRooms;

public:

	//SIGNATURES
	//Declare constructor and destructor
	Cinema(MovieList, int roomAmount);
	Cinema(int roomAmount);
	~Cinema();

	//Declare getters and setters
	int GetRoomAmount();
	void SetRoomAmount(int newAmount);
	RoomNode* GetRoot();
	void SetRoot(RoomNode* root);

	//Method that returns the number of time slots required for a movie
	int TimeSlotsRequired(Movie* scheduledMovie);

	//Methode that generates a schedule for every movie
	void GenerateSchedule();

	//Method that instanciates the Cinema's room list
	void InitiateCinemaRoomVector();

	//Method to create the room binary tree
	void CreateRoomBinaryTree();

	//Method that creates a RoomNode
	RoomNode* CreateRoomNode(Room newRoom);

	//Method that add a RoomNode to binary tree
	RoomNode* AddRoomNode(RoomNode* root, Room newRoom);

	//Method that finds a RoomNode by room ID
	RoomNode* SearchRoomById(RoomNode* root, int roomId);

	//Method to delete a RoomNode by room ID
	//RoomNode* DeleteRoomById(RoomNode* root, int roomId);
};

