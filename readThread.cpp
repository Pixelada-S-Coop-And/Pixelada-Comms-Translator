/*!
@File readThread.cpp
'''thread, for a multi-thread reading from database'''
*/

#include "readThread.h"

int readThread::launch(DBInterface*& myDbClass, int tableId, SlaveInterface** hSlaves)
{
  field currentTag;
  int indexTag = 0;
  int fail = 0;
  
  while(!myDbClass->retFieldFrTable(indexTag,currentTag,tableId))
    {
      for (int l = 0; l < currentTag.fromTags.size(); l++)
	{
	  for (int m = 0; m < currentTag.fromTags[l].size(); m++)
	    {		 
	      fail = fail + hSlaves[l]->readTag(currentTag.fromTags[l].at(m));
	      myDbClass->setFieldValue(tableId,indexTag,hSlaves[l]->retTagValue(currentTag.fromTags[l].at(m)));
	      myDbClass->setFieldValid(tableId,indexTag,hSlaves[l]->retTagValid(currentTag.fromTags[l].at(m)));
	    }
	}
      indexTag++;
    }
  myDbClass->threaded_rTriggerDoneAt(tableId);
  myDbClass->threaded_storeData(tableId);

  return fail;
}
