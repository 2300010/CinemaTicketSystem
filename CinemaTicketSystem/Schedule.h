#pragma once

class Schedule
{
	//Declare variables for the information of the schedule
	float startingTime;
	float endingTime;
	int roomId;

public:

	//SIGNATURES
	//Declare getters and setters
	float GetStartingTime();
	void SetStartingTime(float movieStartTime);
	float GetEndingTime();
	void SetEndingTime(float movieEndTime);
	int GetRoomId();
	void SetRoomId(int idOfChosenRoom);
};

