#include "Reservation.h"

//SIGNATURE
//Declare constructor
Reservation::Reservation(int newReservationId, Client newActualClient, Movie newSelectedMovie) 
{
	this->reservationId = newReservationId;
	this->actualClient = newActualClient;
	this->selectedMovie = newSelectedMovie;
}

//Declare getters and setters
void Reservation::SetReservationId(int newId) 
{
	reservationId = newId;
}

int Reservation::GetReservationId() 
{
	return reservationId;
}

void Reservation::SetActualClient(Client newClient) 
{
	actualClient = newClient;
}

Client Reservation::GetActualClient() 
{
	return actualClient;
}

void Reservation::SetSelectedMovie(Movie newMovie)
{
	selectedMovie = newMovie;
}

Movie Reservation::GetSelectedMovie() 
{
	return selectedMovie;
}