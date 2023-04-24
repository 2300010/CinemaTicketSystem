#pragma once

#include <queue>
#include <stack>
#include "Reservation.h"

class ReservationManager
{
	//Declare queue of ongoing reservations
	queue<Reservation> ongoingReservations;

	//Declare stack of completed reservations
	stack<Reservation> completedReservations;

	int numberOfReservation = 0;
	

public:

	//SIGNATURE
	
	//Declare constructors and destructor
	ReservationManager();
	~ReservationManager();
	
	//Method that shows the posibilities of movies
	void MovieSelection(Cinema localCinema, Client newClient);

	//Method that sets the schedule choice of the user
	Schedule SelectedSchedule(char selectedTimeSlot, vector<Schedule> scheduleList);

	//Method that manages the choice of time slot
	bool TimeSlotSelection(char selectedTimeSlot);

	//Method that displays all available movies
	void DisplayAvailableMovies(Cinema localCinema);

	//Method that displays all schedules by movie
	vector<Schedule> DisplayScheduleByMovie(Cinema localCinema, Movie* selectedMovie);

	//Method that create a reservation
	Reservation CreateReservation(Client actualClient, Schedule selectedSchedule);

	//Method that adds a reservation to the queue
	void AddReservationToQueue(Reservation newReservation);

	//Method that dequeues a reservation and add the reservation to the stack
	void ReservationCompleted(int reservationId);
};

