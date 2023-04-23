#pragma once

#include <queue>
#include <stack>
#include "Reservation.h"
#include "Cinema.h"

class ReservationManager
{
	//Declare queue of ongoing reservations
	queue<Reservation> ongoingReservations;

	//Declare stack of completed reservations
	stack<Reservation> completedReservations;


public:

	//SIGNATURE
	//Method that adds a reservation to the queue
	void AddReservationToQueue(Reservation newReservation);

	//Method that dequeues a reservation and add the reservation to the stack
	void ReservationCompleted(int reservationId);
};

