#include "Cinema.h"

//DEFINITIONS

//Declare constructor and destructor
Cinema::Cinema(MovieList, int roomAmount) 
{
	try
	{
		this->roomAmount = roomAmount;

		InitiateCinemaRoomVector();

		CreateRoomBinaryTree();
	}
	catch (...)
	{

	}
}

Cinema::Cinema(int roomAmount) 
{
	try
	{
		this->roomAmount = roomAmount;

		InitiateCinemaRoomVector();

		CreateRoomBinaryTree();
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

Cinema::RoomNode* Cinema::GetRoot() 
{
	try
	{
		return this->root;
	}
	catch (...)
	{

	}
}

void Cinema::SetRoot(RoomNode* newRoot) 
{
	try
	{
		this->root = newRoot;
	}
	catch (...)
	{

	}
}

//Methode that generates a schedule for every movie
void Cinema::GenerateSchedule() 
{
	try
	{

	}
	catch (...)
	{

	}
}

//Method that instanciates the Cinema's room list
void Cinema::InitiateCinemaRoomVector() 
{
	//Loop to initiate every room of cinema
	for (int i = 0;  i < roomAmount;  i++)
	{
		if (i < 5) 
		{
			//Declare a room temporary room object
			Room tempRoom(i + 1, 250, 10, Regular);

			//Add tempRoom to room list
			cinemaRooms.push_back(tempRoom);
		}
		else if (i < 6)
		{
			//Declare a room temporary room object
			Room tempRoom(i + 1, 200, 13, ThreeD);
			
			//Add tempRoom to room list
			cinemaRooms.push_back(tempRoom);
		}
		else
		{
			//Declare a room temporary room object
			Room tempRoom(i + 1, 100, 18, AVX);

			//Add tempRoom to room list
			cinemaRooms.push_back(tempRoom);
		}	
	}
}

//Method to create the room binary tree
void Cinema::CreateRoomBinaryTree() 
{
	try
	{
		//Declare an empty node for the start of creation
		//RoomNode* root = GetRoot();

		//Insert the rooms
		SetRoot(AddRoomNode(root, cinemaRooms.at(3)));

		SetRoot(AddRoomNode(root, cinemaRooms.at(1)));
		SetRoot(AddRoomNode(root, cinemaRooms.at(5)));

		SetRoot(AddRoomNode(root, cinemaRooms.at(0)));
		SetRoot(AddRoomNode(root, cinemaRooms.at(2)));
		SetRoot(AddRoomNode(root, cinemaRooms.at(4)));
		SetRoot(AddRoomNode(root, cinemaRooms.at(6)));
	}
	catch (...)
	{

	}
}

//Method that creates a RoomNode
Cinema::RoomNode* Cinema::CreateRoomNode(Room newRoom)
{
	try
	{
		//Instanciate a new RoomNode
		RoomNode* newRoomNode = new RoomNode(newRoom, nullptr, nullptr);

		return newRoomNode;
	}
	catch (...)
	{

	}
}

//Method that add a RoomNode to binary tree
Cinema::RoomNode* Cinema::AddRoomNode(RoomNode* root, Room newRoom)
{
	try
	{
		//Verify if root of the tree is NULL
		if (root == NULL)
		{
			//Since there is no root, create new RoomNode with newRoom as root
			return CreateRoomNode(newRoom);
		}

		if (newRoom.GetIdNumber() < root->room.GetIdNumber())
		{
			root->left = AddRoomNode(root->left, newRoom);
		}
		else if (newRoom.GetIdNumber() > root->room.GetIdNumber())
		{
			root->right = AddRoomNode(root->right, newRoom);
		}

		return root;
	}
	catch (...)
	{

	}
}

//Method that finds a RoomNode by room ID
Cinema::RoomNode* Cinema::SearchRoomById(RoomNode* root, int roomId) 
{
	try
	{
		//Verify if root is null or root is equal to roomId
		if (root == NULL || root->room.GetIdNumber() == roomId)
		{
			//Return root
			return root;
		}

		//Verify if newRoom ID is smaller than the root's ID
		if (roomId < root->room.GetIdNumber())
		{
			//Return left in SearchRoomById
			return SearchRoomById(root->left, roomId);
		}

		//If both conditions of both If are false, return right in SearchRoomById
		return SearchRoomById(root->right, roomId);
	}
	catch (...)
	{

	}
}

//Method to delete a RoomNode by room ID
//Cinema::RoomNode* Cinema::DeleteRoomById(RoomNode* root, int roomId) 
//{
//	try
//	{
//		
//	}
//	catch (...)
//	{
//
//	}
//}