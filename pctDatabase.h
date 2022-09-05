/*!
@File pctDatabase.h
*/

#ifndef _PCT_DATABASE_
#define _PCT_DATABASE_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <QMutex>

#include "qtdatabase.h"
#include "config.h"
#include "pctTriggersTable.h"
#include "pctDataTable.h"

/*! Database interface class, derived from pvbrowser addons examples */
class DBInterface : public qtDatabase
{
 public:
  DBInterface() : qtDatabase(){};
  ~DBInterface();
  
  int setup(databaseParameters dbParams,tableParameters* tablesParams);
  int createTriggersTable();
  int start();
  //sql functions
  int storeData();
  int storeData(int id , std::vector<field> tags);
  int storeData(int tableId);
  int threaded_storeData(int tableId);
  int retrieveData(int id);
  //returning private members data and/or attributes functions
  int retNumTables(){return parameters.numTables;};
  int retNumFields(int table);
  char * retFieldTag(int table,int field);
  int retFieldValid(int table,int field);
  int retFieldValue(int table,int field);
  int retDataFrTable(std::vector <field> & fields, int tableId);
  int retFieldFrTable(int index,field & field, int tableId);
  //setting private members data and/or attributes functions
  int setFieldValid(int table,int field, int valid);
  int setFieldValue(int table,int field, int value);
  //triggers functions
  int lockTables();
  int lockTable(int id);  
  int unlockTable(int id);
  int isTableLocked(int id);
  int takeTriggers();
  int takeTimeTriggers();
  int takeSQLTriggers();
  int resetTriggers();
  int resetTimeTriggers();
  int resetSQLTriggers();
  int wTriggerDoneAt(int index);
  int rTriggerDoneAt(int index);
  int threaded_rTriggerDoneAt(int index);
  int retWTabsList(std::vector <int> & tablesList);
  int retRTabsList(std::vector <int> & tablesList);
  //linking fields with communications
  std::vector<std::vector <int>> retFieldLink(int table, int field);
  int setFieldLink(int table, int field, int slave, int tag);
  int fieldLink(int table, int field, int slave, int tag);
  //debug functions
  int showTriggers();
  
  
 private:
  databaseParameters parameters;
  DBDataTable** tables;
  DBTriggersTable* triggersTable;
  std::vector<field*> triggersLst;
  std::vector<int> timeTriggersLst;
};




#endif
