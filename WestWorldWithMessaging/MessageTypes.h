#ifndef MESSAGE_TYPES
#define MESSAGE_TYPES

#include <string>

enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
  Msg_Saloon,
  Msg_Drunk,
  Msg_Sleep,
  Msg_NotDrunk,
  Msg_Fight
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  case Msg_Saloon:

	  return "Miner is in the saloon";

  case Msg_Drunk:

	  return "T-Rex is drunk ";
  case Msg_Sleep:

	  return "T-Rex is going to sleep ";

	case Msg_NotDrunk:

	  return "T-Rex is having fun ";

	case Msg_Fight:
		return "Miner want to fight the Trex ";


  default:

    return "Not recognized!";
  }
}

#endif