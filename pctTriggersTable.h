/*!
@File pctTriggersTable.h
*/

#ifndef _PCT_TRIGGERSTABLE_
#define _PCT_TRIGGERSTABLE_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>

#include "config.h"
#include "pctTable.h"

/*! Database triggers table interface class */
class DBTriggersTable : public DBTable
{
 public:
  DBTriggersTable(tableParameters tableParams) : DBTable(tableParams) {}
  ~DBTriggersTable();
  //creation
  int create(databaseParameters* dbParameters,char **query, char ***initQuery, int **nTrigs);
  int creationSqlite(char **sql);
  int creationMysql(char **sql);
  int initValuesSqlite(char ***sql, int ** nTrigs);
  int initValuesMysql(char ***sql, int ** nTrigs);
  //storing
  //int store(databaseParameters* parameters,char **query);
  //int storeSqlite(char **sql);
  //int insertSqlite(char **sql);
  //int updateSqlite(char **sql);
  //int storeMysql(char **sql);
  //int insertMysql(char **sql);
  //int updateMysql(char **sql);
  //sql
  int sqlTrgsTgd(char *& sql);
  int sqlResetTg(char *& sql, char *triggerName);
  int sqlTrgsDone(char *& sql);
  //
  int updtTrgsOn(std::vector <char*> triggersOn);
  int updtTrgsDone(std::vector <field*> triggersLst);
 
  //return private members
  int retNumFields(){return parameters.numFields;};
  char* retFieldTag(int field);
  int retFieldValid(int field);
  int retFieldValue(int field);
  int* retLink(int field);
  int retNoRepeatedFields(char***);
  int retTgsTgd(field ***, int **);
  int retTgsLst(std::vector <field*> & triggers);
  //set attributes
  int setFieldValid(int field, int valid);
  int setFieldValue(int field, int value);
  int setLink(int field, int slave, int tag);
  //debug
  int showTriggers();

};


#endif
