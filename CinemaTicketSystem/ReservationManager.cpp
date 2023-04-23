#include "ReservationManager.h"

//DEFINITIONS
//Method that adds a reservation to the queue
void ReservationManager::AddReservationToQueue(Reservation newReservation)
{
	ongoingReservations.push(newReservation);
}

//Method that dequeues a reservation and add the reservation to the stack
void ReservationManager::ReservationCompleted(int reservationId)
{
	if (ongoingReservations.front().GetReservationId() == reservationId) 
	{
		completedReservations.push(ongoingReservations.front());

		ongoingReservations.pop();
	}
	else
	{
		if()
	}
}