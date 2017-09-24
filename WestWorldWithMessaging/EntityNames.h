#ifndef NAMES_H
#define NAMES_H

#include <string>

enum 
{
  ent_Miner_Bob,

  ent_Elsa,

  ent_Trex
};

inline std::string GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_Miner_Bob:

    return "Miner Bob";

  case ent_Elsa:
    
    return "Elsa"; 

  case ent_Trex:

<<<<<<< HEAD
	  return "Trex";
=======
	  return "T-rex";
>>>>>>> 4386533b8d4593fa2366817e47b4ac979d6ef1c5

  default:

    return "UNKNOWN!";
  }
}

#endif