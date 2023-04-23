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

		//GenerateSchedule();
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

//Method that manages and returns the number of time slots required for a movie
int Cinema::TimeSlotsRequired(Movie* scheduledMovie)
{
	//Declare variable to receive movie length
	float movieLength = scheduledMovie->GetLength();

	//Verify if movie length fits perfectly in time slots
	if (fmod(movieLength, 1) == 0) 
	{
		return movieLength;
	} //If it does not
	else
	{
		return movieLength + 1;
	}
}

//Methode that generates a schedule for every movie
void Cinema::GenerateSchedule() 
{
	try
	{
		//Declare a variable to represent actual time slot and to receive number of time slots required
		int actualTimeSlot = OPENING_TIME;
		int tempTimeSlotsRequired = 0;
		int cinemaScheduleLength = 0;

		//Loop for every cinema rooms
		for (int i = 0; i < roomAmount; i++)
		{
			//Set timeSlotsRequired
			tempTimeSlotsRequired = TimeSlotsRequired(availableMovies.getNodeAtPosition(i));

			//Loop until all time slots are filled and until length of movie ends after closing
			while (actualTimeSlot < CLOSING_TIME && actualTimeSlot + tempTimeSlotsRequired <= CLOSING_TIME)
			{
				//Generate a new schedule for actual movie
				Schedule movieSchedule(availableMovies.getNodeAtPosition(i), actualTimeSlot,
					actualTimeSlot + availableMovies.getNodeAtPosition(i)->GetLength(),
					SearchRoomById(root, i)->room.GetIdNumber());

				//Set cinemaSchedule "i" to the movieSchedule
				cinemaSchedule[i] = movieSchedule;

				//Loop until every required time slots required are filled
				for (int j = 0; j < tempTimeSlotsRequired; j++)
				{
					actualTimeSlot++;
				}
			}

			//Reset actualTimeSlot
			actualTimeSlot = OPENING_TIME;
		}
	}
	catch (...)
	{

	}
}

//Method that instanciates the Cinema's room list
void Cinema::InitiateCinemaRoomVector() 
{
	try
	{
		//Loop to initiate every room of cinema
		for (int i = 0; i < roomAmount; i++)
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
	catch (...)
	{

	}
}

//Method to create the room binary tree
void Cinema::CreateRoomBinaryTree() 
{
	try
	{
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


//				TEST!!
//void main() 
//{
//	//TEST BINARY TREE
//    int roomAmount = 7;
//
//	//cout << "The room id is: " << Cinema::SearchRoomById(Cinema::GetRoot(), 7)->room.GetIdNumber() << endl;
//}