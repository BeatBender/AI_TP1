#include <fstream>
#include <time.h>

#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "T-rex.h"


std::ofstream os;

int main()
{
	//define this to send output to a text file (see locations.h)
#ifdef TEXTOUTPUT
	os.open("output.txt");
#endif

	//seed random number generator
	srand((unsigned)time(NULL));

	//create a miner
	Miner* Bob = new Miner(ent_Miner_Bob);

	//create his wife
	MinersWife* Elsa = new MinersWife(ent_Elsa);

	//create a drunk T-rex
	Trex* _trex = new Trex(ent_Trex);

	//register them with the entity manager
	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Elsa);
	EntityMgr->RegisterEntity(_trex);

<<<<<<< HEAD
  //run Bob and Elsa through a few Update calls
  for (int i = 0; i < 30; ++i)
  {
	  Bob->Update(_trex->GetDrunkLevel());
	  Elsa->Update();
	  _trex->Update(Bob->Location());
	  Sleep(1000);
  }

	  delete Bob;
	  delete Elsa;
	  delete _trex;
  

  //wait for a keypress before exiting
  PressAnyKeyToContinue();


  return 0;
}
=======
	//run Bob and Elsa through a few Update calls
	for (int i = 0; i < 30; ++i)
	{
		
		Bob->Update();
		Elsa->Update();
		_trex->Update();

	}

	delete Bob;
	delete Elsa;
	delete _trex;
>>>>>>> 21df958cf35688043e098c8ff4e4e9f0202569f9

	//wait for a keypress before exiting
	PressAnyKeyToContinue();


	return 0;

}


