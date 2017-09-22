#include "T-rex.h"


bool Trex::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}
int Trex::Update(int miner_location)
{
	//set text color to green
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	MinerLocations = miner_location;

	m_pStateMachine->Update();

	return 0;
}

void Trex::Update()
{

	return;
}

bool Trex::Drunk()const
{
	if (m_drunklevel >= maxdrunklevel)  
		return true; 
	else if (m_drunklevel <= maxdrunklevel-1)
		return false;
	
	return false;
}