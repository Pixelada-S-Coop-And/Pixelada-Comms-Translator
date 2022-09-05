/*!
@File pixeladaCT.h
*/

#ifndef _PIXELADA_CT_
#define _PIXELADA_CT_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <execinfo.h>
#include <signal.h>

#include <time.h>

#include "pctDatabase.h"
#include "pctSlave.h"
#include "libgStools.h"
#include "config.h"
#include "readThread.h"

#include "commDaemon.h"


#ifdef __FUCKIN_WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

static int lExit = 0;

/*!server capture class, it setup capture and run&check it */
class pixeladaCT 
{
 public:
 pixeladaCT();
  ~pixeladaCT();
  //initialization functions
  int startCommunications();
  int initComm();
  //checking fucntions
  int checkDB(); 
  int checkComm();  
  //capturing functions
  int loop();
  int lockTables();
  int dataCapture();
  int dataToComm();
  int dataToDB();
  int storeDB();
  int getTriggers();
  int delTriggers();
  //tools
  int linkTags();
  //DEBUGGING FUNCTIONS
  int showDBData();
  int showDBDataLinkage();
  int showTriggers();
  //EXIT HANDLER
  static void exitHandler(int s){lExit = 1;};
  static void sigsevHandler(int s);
  int stopComm();

  
 private:
  //database configuration parser
  ConfigParser* confParser = NULL;
  ////databases
  //number of database handlers
  int nDBs;
  //database handler
  DBInterface** hDatabase = NULL;
  ////communications
  //number of slaves handlers
  int nSlaves;
  SlaveInterface** hSlaves = NULL;
  CommDaemon** comms = NULL;

};


#endif
