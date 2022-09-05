/**
@file commDaemon.h
*/

#ifndef _COMMDAEMON_
#define _COMMDAEMON_

#include <iostream>
#include <string.h>
#include <vector>
#include <memory>

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <vector>

#include <unistd.h>

#include "config.h"
#include "iniConfigurator.h"



//tools
int renameOldLog(char** logPath,const char* name);
int setExecutable(char* protocol, char ** executable, const char * name);
void* launchMBUS(void * parameters);

/*launching,checking,logging... communication daemon manager class*/
class CommDaemon
{
 public:
  CommDaemon(mbSlaves slaveParams);
  ~CommDaemon();
  
  int iniDaemon();
  int iniMBTCP();
  
  int launchDaemon(int slave, int commId, char* protocol);
  int launchDaemon();
  int checkDaemon(int slave);

  mbSlaves retParams(){ return slaveP;};
  //threads
  pthread_t* declareThread(int nSlave);
  
 private:
  int *nPipe;
  std::vector<pthread_t*> threads;
  mbSlaves slaveP;
  int dType;
};
#endif
