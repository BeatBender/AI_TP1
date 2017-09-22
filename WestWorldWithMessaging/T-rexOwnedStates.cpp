#include "T-rexOwnedStates.h"
#include "fsm/State.h"
#include "T-rex.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//------------------------------------------------------------------------methods for TerrorizeCustomers
TerrorizeCustomers* TerrorizeCustomers::Instance()
{
	static TerrorizeCustomers instance;

	return &instance;
}

void TerrorizeCustomers::Enter(Trex* pTrex)
{
	
}

void TerrorizeCustomers::Execute(Trex* pTrex)
{
	if (pTrex->GetMinerLocation() == 3)
	{
		pTrex->GetFSM()->ChangeState(TrexFighting::Instance());
	}
}

void TerrorizeCustomers::Exit(Trex* pTrex)
{

}

bool TerrorizeCustomers::OnMessage(Trex* pTrex, const Telegram& msg)
{

	return false;
}

//------------------------------------------------------------------------methods for TrexSleeping
TrexSleeping* TrexSleeping::Instance()
{
	static TrexSleeping instance;

	return &instance;
}

void TrexSleeping::Enter(Trex* pTrex)
{

}

void TrexSleeping::Execute(Trex* pTrex)
{
	pTrex->DecreaseDrunkLevel();

	cout << "\n" << GetNameOfEntity(pTrex->ID()) << ": " << "ZZZZZZZZZZ";

	if (!pTrex->Drunk())
	{
		pTrex->GetFSM()->ChangeState(TrexTalking::Instance());
	}

}

void TrexSleeping::Exit(Trex* pTrex)
{

}

bool TrexSleeping::OnMessage(Trex* pTrex, const Telegram& msg)
{

	return false;
}

//------------------------------------------------------------------------methods for TrexTalking
TrexTalking* TrexTalking::Instance()
{
	static TrexTalking instance;

	return &instance;

}

void TrexTalking::Enter(Trex* pTrex)
{

}

void TrexTalking::Execute(Trex* pTrex)
{
	pTrex->IncreaseDrunkLevel();

	cout << "\n" << GetNameOfEntity(pTrex->ID()) << ": " << "WARAARARRARA";

	if (pTrex->Drunk())
	{
		pTrex->GetFSM()->ChangeState(TrexSleeping::Instance());
	}

}

void TrexTalking::Exit(Trex* pTrex)
{

	//cout << "\n" << GetNameOfEntity(pTrex->ID()) << ": "
		//<< "**BRRRURUGWWG**";

}

bool TrexTalking::OnMessage(Trex* pTrex, const Telegram& msg)
{
	return false;
}

//------------------------------------------------------------------------methods for TrexFighting
TrexFighting* TrexFighting::Instance()
{
	static TrexFighting instance;

	return &instance;
}

void TrexFighting::Enter(Trex* pTrex)
{

}

void TrexFighting::Execute(Trex* pTrex)
{
	if (pTrex->GetDrunkLevel() == 8)
	{
		pTrex->GetFSM()->ChangeState(TrexSleeping::Instance());
	}
}

void TrexFighting::Exit(Trex* pTrex)
{

}

bool TrexFighting::OnMessage(Trex* pTrex, const Telegram& msg)
{

	return false;
}