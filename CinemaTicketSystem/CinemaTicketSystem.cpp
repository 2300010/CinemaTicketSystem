// CinemaTicketSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CinemaTicketSystem.h"
#include "Cinema.h"

int main()
{
    //TEST BINARY TREE
    int roomAmount = 7;

    Cinema cinema(roomAmount);

    cout << "All Good?" << endl;

    cinema.SetAvailableMovies();

    system("Pause");

    cout << cinema.GetAvailableMovies().getNodeAtPosition(2)->GetTitle();

   // cout << "The room id is: " << cinema.SearchRoomById(cinema.GetRoot(), 7)->room.GetIdNumber() << endl;

    
}


