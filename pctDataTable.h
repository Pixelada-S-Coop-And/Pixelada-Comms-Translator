/*!
@File piDataTable.h
*/

#ifndef _PIDATATABLE_
#define _PIDATATABLE_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include <initializer_list>

#include "config.h"

#include "pctTable.h"


/*! Database table interface class */
class DBDataTable : public DBTable
{
 public:
 DBDataTable(tableParameters tableParams) : DBTable(tableParams) {}
  ~DBDataTable(){};
  //creation
  int create(databaseParameters* parameters,int * nQueries,char ***query);
  int creationSqlite(char **sql);
  int creationMysql(char **sql);
  int initValuesSqlite(int num,char ***sql);
  int initValuesMysql(int num,char ***sql);
  //storing
  int store(databaseParameters* parameters,char **query);
  int storeSqlite(char **sql);
  int insertSqlite(char **sql);
  int updateSqlite(char **sql);
  int storeMysql(char **sql);
  int insertMysql(char **sql);
  int updateMysql(char **sql);
  
  //triggering
  int isTimeTriggered();
  int isTimeInitialized();
  int isReadTriggered();
  int isWriteTriggered();
  int retReadTrigger(field*);
  int retWriteTrigger(field*);
  int startTiming(){read = time(0); return 0;};
  //private members
  std::vector<std::vector <int>> retLink(int field);
  
  //set attributes
  int setLink(int field, int slave, int tag);
  int updateData(std::vector<field> data);
  
private:  
  time_t read = NULL;
  
};

#endif
