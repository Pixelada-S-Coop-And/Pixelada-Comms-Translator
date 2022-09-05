/*!
@File iniConfigurator.h
*/

#ifndef _INI_CONFIGURATOR_
#define _INI_CONFIGURATOR_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

#include "config.h"

class IniConfigurator
{
 public:
  IniConfigurator(){return;};
  ~IniConfigurator(){return;};

  int iniMBTCPCreate(char * path, mbSlaves & params);
  int usingSocket(mbSlaves& parameters);
  
  int writMBTCPSocket(FILE* pFile, mbSlaves  params);
  int writMBTCPCycles(FILE* pFile, mbSlaves & params);  
  int writCycles(FILE* pFile, mbSlaves* parameters);
  int rudeCycles(mbSlaves* parameters, int * first);
  int fineCycles(mbSlaves* parameters, int * first, int rudeCycles);
  int cycleIsValid(mbSlaves* parameters, int address);
  
  int tagTypeValid(const char* type);

};
#endif
