#ifndef TREX_H
#define TREX_H



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
const int maxdrunklevel = 8;


class Trex: public BaseGameEntity
{
private:
	//an instance of the state machine class
	StateMachine <Trex>*  m_pStateMachine;

	location_type         m_Location;

	//before 5, Trex is talking with other customers. Between 5 and 8, Trex is terrorizing/fighting other customers. 
	//After 8, Trex is sleeping on the bar. Drunklevel is decreasing. At 0, Trex wakes up and talks to customers again.
	int m_drunklevel;
	

public:

	Trex(int id) :m_Location(saloon),
		m_drunklevel(0),
		BaseGameEntity(id)

	{
		//set up state machine
		m_pStateMachine = new StateMachine<Trex>(this);

		m_pStateMachine->SetCurrentState(TrexTalking::Instance());

		

		/* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
	}

	~Trex() { delete m_pStateMachine; }

	//this must be implemented
<<<<<<< HEAD
	
=======
<<<<<<< HEAD
=======
	void Update(int);
>>>>>>> 21df958cf35688043e098c8ff4e4e9f0202569f9
>>>>>>> 4386533b8d4593fa2366817e47b4ac979d6ef1c5
	void Update();
	int Update(int);
	

	//so must this
	virtual bool  HandleMessage(const Telegram& msg);


	StateMachine<Trex>* GetFSM()const { return m_pStateMachine; }



	//-------------------------------------------------------------accessors
	location_type Location()const { return m_Location; }
	void          ChangeLocation(location_type loc) { m_Location = loc; }

	bool          Drunk()const;
	int			  GetDrunkLevel()	   { return m_drunklevel; }
	
	void          DecreaseDrunkLevel() { m_drunklevel = 0; }
	void          IncreaseDrunkLevel() { m_drunklevel += 1; }

	

};



#endif
