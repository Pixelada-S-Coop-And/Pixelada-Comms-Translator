/*!
@File readThread.h
*/

#ifndef _READ_THREAD_
#define _READ_THREAD_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <QThread>

#include "qtdatabase.h"
#include "pctDatabase.h"
#include "config.h"
#include "pctTriggersTable.h"
#include "pctDataTable.h"
#include "pctSlave.h"

/*! Database interface class, derived from pvbrowser addons examples */
class readThread : public QThread
{
 public:
  readThread(){};
  ~readThread(){};

  int launch(DBInterface*& , int, SlaveInterface**);
 private:

};




#endif
