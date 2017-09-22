#include "T-rex.h"


bool Trex::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}
int Trex::Update(int miner_location)
{
	//set text color to green
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}

bool Trex::Drunk()const
{
	if (m_drunklevel >= maxdrunklevel)  
		return true; 
	else if (m_drunklevel <= maxdrunklevel-1)
		return false;
	
	
}