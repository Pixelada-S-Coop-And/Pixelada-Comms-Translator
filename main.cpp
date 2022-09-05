/*!
@File main.cpp
'''program starts here'''
*/

#include "pvapp.h"
#include "pixeladaCT.h"


int pvMain(PARAM *p)
{
  return 0;
}

/* main function,  it could be integrate in other programs, or pvbrwoser*/
int main(int ac, char **av)
{
  pixeladaCT* server;

  int ret =0;
  std::cout << "INFO: Pixelada Comms Translator version: " << sVERSION << std::endl;
  server = new pixeladaCT();
  std::cout << "INFO: start capturing..." << std::endl;
  server->startCommunications();
  ret = server->loop();
  delete server;
  std::cout << "INFO: Thanks for using Pixelada Comms Translator!" << std::endl; 
  return ret;
}
