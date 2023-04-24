#pragma once

#include <iostream>
#include "Client.h"
#include "Cinema.h"


class Reservation
{
	//Declare variables for the informations of a reservation
	int reservationId;
	Client actualClient;
	Schedule selectedSchedule;

public:
	
	//SIGNATURE
	//Declare constructor
	Reservation(int newReservationId, Client newActualClient, Schedule newSelectedSchedule);
	Reservation();

	//Declare getters and setters
	void SetReservationId(int newId);
	int GetReservationId();
	void SetActualClient(Client newClient);
	Client GetActualClient();
	void SetSelectedSchedule(Schedule newSelectedSchedule);
	Schedule GetSelectedSchedule();

};

