//#include "HeapArray.h"
#include "HeapSkew.h"
//#include "PQHeap.h"
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;
using CSC2110::String;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

while(true)
{
   HeapSkew<CD>* sh = new HeapSkew<CD>(&CD::compare_items);

   ListArrayIterator<CD>* iter = cds->iterator();

   int i = 0;

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      sh->heapInsert(cd);
      i++;
     //cout << i << endl;
   }
   delete iter;

   //cout << "after delete iter" << endl;

   i = 0;

   while(!(sh->heapIsEmpty()))
   {
     //cout << "before remove" << endl;

      CD* cd = sh->heapRemove();
      //cd->displayCD();
      i++;
      //cout << i << endl;
   }

   //cout << "before delete sh" << endl;
   delete sh;
}
   deleteCDs(cds);
   delete cds;

   return 0;
}
