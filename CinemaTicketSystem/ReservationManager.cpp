#include "ReservationManager.h"

//DEFINITIONS

//Declare constructors
ReservationManager::ReservationManager() {}

ReservationManager::~ReservationManager() {}

//Method that manages the movie choice of the user
void ReservationManager::MovieSelection(Cinema localCinema, Client newClient) 
{
	try
	{
		//Declare variables for user choices
		char movieSelected = ' ';
		char timeSlotSelected = ' ';

		//Declare variable for temporary values
		Schedule tempSelectedSchedule;
		Reservation tempReservation;
		vector<Schedule> tempScheduleList;

		cout << "Please select the movie you want to see with the number associated: \n";

		do
		{
			DisplayAvailableMovies(localCinema);
			cout << "\t0. Quit this menu\n";
			cout << "Enter choice here: ";
			cin >> movieSelected;
			cout << endl;

			switch (movieSelected)
			{
			case '1':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema, 
						localCinema.GetAvailableMovies().getNodeAtPosition(0));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected)) 
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '2':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(1));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '3':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(2));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '4':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(3));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '5':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(4));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '6':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(5));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '7':
			{
				cout << "Please select the time slot you prefer in the following list: \n";

				do
				{
					tempScheduleList = DisplayScheduleByMovie(localCinema,
						localCinema.GetAvailableMovies().getNodeAtPosition(6));

					cout << "\t0. Go back to last menu\n";
					cout << "Enter choice here: ";

					cin >> timeSlotSelected;

					if (TimeSlotSelection(timeSlotSelected))
					{
						tempSelectedSchedule = SelectedSchedule(timeSlotSelected, tempScheduleList);

						tempReservation = CreateReservation(newClient, tempSelectedSchedule);

						AddReservationToQueue(tempReservation);

						cout << "Your reservation as been made.\n";
					}

				} while (timeSlotSelected != '0');
			}
			break;
			case '0':
			{
				cout << "You are quitting this menu!\n";
			}
			break;
			default:
			{
				cout << "Error! Please enter a valid option (number associated) base on the following options: \n";
			}
			break;
			}
		} while (movieSelected != '0');
	}
	catch (...)
	{

	}
}

//Method that manages time slot choice of the user
Schedule ReservationManager::SelectedSchedule(char selectedTimeSlot, vector<Schedule> scheduleList)
{
	try
	{
		Schedule selectedSchedule;

		int convertedTimeSlot = (int)selectedTimeSlot - 1;

		if (convertedTimeSlot > 0 || convertedTimeSlot < 8) 
		{
			selectedSchedule = scheduleList.at(convertedTimeSlot);
		}

		return selectedSchedule;
	}
	catch (...)
	{

	}
}

//Method that manages the choice of time slot
bool ReservationManager::TimeSlotSelection(char selectedTimeSlot) 
{
	switch (selectedTimeSlot)
	{
	case '1':
	{
		return true;
	}
		break;
	case '2':
	{
		return true;
	}
		break;
	case '3':
	{
		return true;
	}
		break;
	case '4':
	{
		return true;
	}
		break;
	case '5':
	{
		return true;
	}
		break;
	case '6':
	{
		return true;
	}
		break;
	case '7':
	{
		return true;
	}
		break;
	case '0':
	{
		cout << "You are going back to the last menu!\n";
		cout << "\nPlease select the time slot you prefer in the following list: \n";

		return false;
	}
		break;
	default: 
	{
		cout << "Error! Please enter a valid option (number associated) base on the following options: \n";

		return false;
	}
		break;
	}
}

//Method that displays all available movies
void ReservationManager::DisplayAvailableMovies(Cinema localCinema)
{
	try
	{
		//Loop for every available movies
		for (int i = 0; i < localCinema.GetAvailableMovies().getLength(); i++)
		{
			cout << "\t" << i + 1 << ". " << localCinema.GetAvailableMovies().getNodeAtPosition(i)->GetTitle() << endl;
		}
	}
	catch (...)
	{

	}
}

//Method that displays all schedules by movie
vector<Schedule> ReservationManager::DisplayScheduleByMovie(Cinema localCinema, Movie* selectedMovie)
{
	try
	{
		int tempIndex = 1;

		vector<Schedule> tempScheduleList;

		for (int i = 0; i < localCinema.GetCinemaSchedule().size(); i++)
		{
			if (localCinema.GetCinemaSchedule().at(i).scheduledMovie == selectedMovie)
			{
				cout << "\t" << tempIndex << ". " << selectedMovie->GetTitle() << endl;
				cout << "\tSchedule: " << localCinema.GetCinemaSchedule().at(i).GetStartingTime() << ":00" << endl;

				tempScheduleList.push_back(localCinema.GetCinemaSchedule().at(i));

				tempIndex++;
			}
		}

		return tempScheduleList;
	}
	catch (...)
	{

	}
}

//Method that create a reservation
Reservation ReservationManager::CreateReservation(Client actualClient, Schedule selectedSchedule) 
{
	try
	{
		numberOfReservation++;

		Reservation newReservation = Reservation(numberOfReservation, actualClient, selectedSchedule);

		return newReservation;
	}
	catch (...)
	{

	}
}

//Method that adds a reservation to the queue
void ReservationManager::AddReservationToQueue(Reservation newReservation)
{
	try
	{
		ongoingReservations.push(newReservation);
	}
	catch (...)
	{

	}
}

//Method that dequeues a reservation and add the reservation to the stack
void ReservationManager::ReservationCompleted(int reservationId)
{
	try
	{
		if (ongoingReservations.front().GetReservationId() == reservationId)
		{
			completedReservations.push(ongoingReservations.front());

			ongoingReservations.pop();
		}
		else
		{
			//if(localCinema.SearchRoomById())
		}
	}
	catch (...)
	{

	}
}

//void main() 
//{
//	ReservationManager myManager = ReservationManager();
//
//	myManager.MovieSelection();
//}

