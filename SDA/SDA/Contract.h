#pragma once
#include <string>
class Contract
{
private:
	int daysRemaining;
	std::string playerName;
public:
	Contract() {}									//default contructor
	Contract(int daysRemaining, const std::string& playerName);
	int getDays() { return daysRemaining; }			//function that returns the no. days remaining on the contract
	std::string getPlayer() { return playerName; }	//function that return the name of the Player that signed the contract
	void sim(int s) { this->daysRemaining -= s; }	//function that "simulates" a no. days ( is subtracts fom the no. days on the contract the no. days simulated)
	~Contract() {}									//default destructor
};

