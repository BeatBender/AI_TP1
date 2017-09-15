#ifndef TREX_H_
#define TREX_H_

#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "T-rexOwnedStates.h"
#include "fsm/StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

//T-Rex maximum drunk level
const int maxdrunklevel = 10;

class Trex
{
public:
	Trex();
	~Trex();

private:
	//an instance of the state machine class
	StateMachine<Trex>*  m_pStateMachine;

	location_type         m_Location;

	//before 5, Trex is talking with other customers. Between 5 and 8, Trex is terrorizing/fighting other customers. 
	//After 8, Trex is sleeping on the bar. Drunklevel is decreasing. At 0, Trex wakes up and talks to customers again.
	int m_drunklevel;

};

Trex::Trex()
{
}

Trex::~Trex()
{
}

#endif