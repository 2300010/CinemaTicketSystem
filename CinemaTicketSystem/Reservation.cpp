#include "Reservation.h"

//SIGNATURE
//Declare constructor
Reservation::Reservation(int newReservationId, Client newActualClient, Schedule newSelectedSchedule) 
{
	try
	{
		this->reservationId = newReservationId;
		this->actualClient = newActualClient;
		this->selectedSchedule = newSelectedSchedule;
	}
	catch (...)
	{

	}
}

Reservation::Reservation(){}

//Declare getters and setters
void Reservation::SetReservationId(int newId) 
{
	try
	{
		reservationId = newId;
	}
	catch (...)
	{

	}
}

int Reservation::GetReservationId() 
{
	try
	{
		return reservationId;
	}
	catch (...)
	{

	}
}

void Reservation::SetActualClient(Client newClient) 
{
	try
	{
		actualClient = newClient;
	}
	catch (...)
	{

	}
}

Client Reservation::GetActualClient() 
{
	try
	{
		return actualClient;
	}
	catch (...)
	{

	}
}

void Reservation::SetSelectedSchedule(Schedule newSelectedSchedule)
{
	try
	{
		selectedSchedule = newSelectedSchedule;
	}
	catch (...)
	{

	}
}

Schedule Reservation::GetSelectedSchedule() 
{
	try
	{
		return selectedSchedule;
	}
	catch (...)
	{

	}
}