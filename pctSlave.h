/*!
@File pctSlave.h
*/

#ifndef _PCT_SLAVE_
#define _PCT_SLAVE_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>

#include "config.h"
#include "lib/gStools/libgStools.h"



/*! slave interface class*/
class SlaveInterface
{
 public:
  SlaveInterface(){return;};
  ~SlaveInterface(){delete rlMODBUS; return;};

  int setup(mbSlaves slaveParameters);
  //rlib communications settings
  int setupCommDaemon();
  int setupMBUSTCP();
  //read data
  int readData();
  int readTag(int index);
  int readINT(int index);
  int readWORD(int index);
  //write data
  int writeTag(int index, int slaveAmI, int value);
  //return functions
  int retNumTags(){return parameters.nRegs;};
  char * retTagName(int tag);
  int retTagValue(int tag);
  int retTagValid(int tag);
 protected:
  int calcMemorySize();
 private:
  mbSlaves parameters;
  //daemons
  rlModbusClient*    rlMODBUS = NULL;
};




#endif
