#pragma once

#include <iostream>
#include "Client.h"

class Reservation
{
	//Declare variables for the informations of a reservation
	int reservationId;
	Client actualClient;
	Movie selectedMovie;
	Room selectedRoom;

public:
	
	//SIGNATURE
	//Declare constructor
	Reservation(int newReservationId, Client newActualClient, Movie newSelectedMovie);

	//Declare getters and setters
	void SetReservationId(int newId);
	int GetReservationId();
	void SetActualClient(Client newClient);
	Client GetActualClient();
	void SetSelectedMovie(Movie newMovie);
	Movie GetSelectedMovie();

};

