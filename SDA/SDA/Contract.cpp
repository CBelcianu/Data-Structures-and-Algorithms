#include "Contract.h"

Contract::Contract(int daysRemaining, const std::string & playerName)
/*
	constructor for the Contract class
*/
{
	this->daysRemaining = daysRemaining;
	this->playerName = playerName;
}
