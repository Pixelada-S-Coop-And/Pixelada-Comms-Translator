/*!
@File pctTable.h
*/

#ifndef _PCT_TABLE_
#define _PCT_TABLE_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <time.h>

#include <vector>
#include <string.h>

#include "config.h"


/*! Database table interface class */
class DBTable
{
 public:
  DBTable(tableParameters tableParams);
  ~DBTable();
  //creation
  virtual int create(databaseParameters* parameters,int* nQueries,char ***query){return -1;};
  virtual int creationSqlite(char **sql){return -1;};
  virtual int creationMysql(char **sql){return -1;};
  virtual int initValuesSqlite(int num,char ***sql);
  virtual int initValuesMysql(int num,char ***sql);
  //storing
  virtual int store(databaseParameters* parameters,char **query);
  virtual int storeSqlite(char **sql);
  virtual int insertSqlite(char **sql);
  virtual int updateSqlite(char **sql);
  virtual int storeMysql(char **sql);
  virtual int insertMysql(char **sql);
  virtual int updateMysql(char **sql);
  //new sql standard functions, january 2017, TODO: to improve and insert the old ones
  virtual int sqlSelectAll(databaseParameters dbParameters,char* & sql);
  virtual int sqlSelectAllMysql(char* & sql);
  virtual int sqlSelectAllSqlite(char* & sql);

  virtual int lockOrUnlock(std::vector< std::vector < std::string>> data, int skip);
  virtual int islocked(){ return parameters.locked;};
  virtual void unlock(){parameters.locked = 0;};
  
  //return private members
  int retNumFields(){return parameters.numFields;};
  char * retFieldTag(int field);
  int retFieldValid(int field);
  int retFieldValue(int field);
  int retFields(field ***,int**);
  int retvFields(std::vector < field> & fields);
  int retvField(int index,field & myField);
  int retId(){return parameters.id;};
  
  //set attributes
  int setFieldValid(int field, int valid);
  int setFieldValue(int field, int value);
  int setAllValues(std::vector<std::vector<std::string>> table, int skip);
  int setId(int id);
  
protected:  
  tableParameters parameters;
  
};



#endif
