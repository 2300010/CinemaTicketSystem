#pragma once

#include "Movie.h"

struct Schedule
{
	//Declare variables for the information of the schedule
	Movie* scheduledMovie;
	float startingTime;
	float endingTime;
	int roomId;

public:

	//SIGNATURES
	//Declare constructor
	Schedule();
	Schedule(Movie* scheduledMovie, float startingTime, float endingTime, int roomId);

	//Declare getters and setters
	Movie* GetScheduledMovie();
	void SetScheduledMovie(Movie* scheduledMovie);
	float GetStartingTime();
	void SetStartingTime(float movieStartTime);
	float GetEndingTime();
	void SetEndingTime(float movieEndTime);
	int GetRoomId();
	void SetRoomId(int idOfChosenRoom);
};

