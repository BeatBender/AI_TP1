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
  srand((unsigned) time(NULL));

  //create a miner
  Miner* Bob = new Miner(ent_Miner_Bob);

  //create his wife
  MinersWife* Elsa = new MinersWife(ent_Elsa);

  //create a drunk T-rex
  Trex* _trex = new Trex(2);

  //register them with the entity manager
  EntityMgr->RegisterEntity(Bob);
  EntityMgr->RegisterEntity(Elsa);
  EntityMgr->RegisterEntity(_trex);

  //run Bob and Elsa through a few Update calls
  for (int i=0; i<30; ++i)
  { 

	  Bob->Update(_trex->GetDrunkLevel());
    Elsa->Update();
	_trex->Update(Bob->Location());

  delete Bob;
  delete Elsa;
  delete _trex;

  //wait for a keypress before exiting
  PressAnyKeyToContinue();


  return 0;
}






