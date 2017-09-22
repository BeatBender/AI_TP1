#ifndef TREXOWNEDSTATES
#define TREXOWNEDSTATES

//------------------------------------------------------------------------
//
//  Name:   T-rexOwnedStates.h
//
//  Desc:   All the states that can be assigned to the T-rex class.
//          Note that a global state has not been implemented.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"


class Trex;
struct Telegram;


//------------------------------------------------------------------------
//
// State : TerrorizeCustomers
// In this state, the T-rex is drunk and terrorize the customers by roaring
// and biting. 
//
//
//
//------------------------------------------------------------------------
class TerrorizeCustomers: public State<Trex>
{
public:
	//this is a singleton
	static TerrorizeCustomers* Instance();

	virtual void Enter(Trex* trex);

	virtual void Execute(Trex* trex);

	virtual void Exit(Trex* trex);

	virtual bool OnMessage(Trex* agent, const Telegram& msg);

private:
	TerrorizeCustomers() {}

	//copy ctor and assignment should be private
	TerrorizeCustomers(const TerrorizeCustomers&);
	TerrorizeCustomers& operator=(const TerrorizeCustomers&);
};

//------------------------------------------------------------------------
//
// State : TRexSleeping
// In this state, the T-rex is asleep on the bar from drinking too  much.
//
//
//
//------------------------------------------------------------------------

class TrexSleeping : public State<Trex>
{
public:
	//this is a singleton
	static TrexSleeping* Instance();

	virtual void Enter(Trex* trex);

	virtual void Execute(Trex* trex);

	virtual void Exit(Trex* trex);

	virtual bool OnMessage(Trex* agent, const Telegram& msg);

private:
	TrexSleeping() {}

	//copy ctor and assignment should be private
	TrexSleeping(const TrexSleeping&);
	TrexSleeping& operator=(const TrexSleeping&);
};

//------------------------------------------------------------------------
//
// State : TRexTalking
// In this state, the T-rex is drinking while speaking with other customers,
// it speaks by roaring mostly.
//
//
//------------------------------------------------------------------------
class TrexTalking : public State<Trex>
{
public:
	//this is a singleton
	static TrexTalking* Instance();

	virtual void Enter(Trex* trex);

	virtual void Execute(Trex* trex);

	virtual void Exit(Trex* trex);

	virtual bool OnMessage(Trex* agent, const Telegram& msg);

private:
	TrexTalking() {}

	//copy ctor and assignment should be private
	TrexTalking(const TrexTalking&);
	TrexTalking& operator=(const TrexTalking&);
};
#endif