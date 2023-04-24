// CinemaTicketSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cinema.h"
#include "ReservationManager.h"

int main()
{
    //TEST BINARY TREE
    int roomAmount = 7;

    Client tempClient = Client("Sam", 30);

    Cinema cinema = Cinema(roomAmount);

    cout << "All Good?" << endl;

    cinema.SetAvailableMovies();

    cinema.GenerateSchedule();

    ReservationManager myManager = ReservationManager();

    myManager.MovieSelection(cinema, tempClient);


    system("Pause");

}


