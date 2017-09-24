#include "T-rex.h"


bool Trex::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

<<<<<<< HEAD
=======
	m_pStateMachine->Update();

	return 0;
}

void Trex::Update()
{

	return;
}
>>>>>>> 4386533b8d4593fa2366817e47b4ac979d6ef1c5

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
	
	return false;
}