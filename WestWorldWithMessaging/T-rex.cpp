#include "T-rex.h"


bool Trex::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Trex::Update()
{
	//set text color to blue
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