#ifndef PROCESSHANDLER
#define PROCESSHANDLER

#include "spawnHandler.h"
#include <vector>
#include <string>

using namespace std;
class ProcessHandler
{
    public:
       vector<string> processList;

       ProcessHandler()
       {
           processList.push_back("P1");
           processList.push_back("P2");
           processList.push_back("P3");

           SpawnHandler spH;
           for(int i =0; i<processList.size(); i++)
           {
               int PID = spH.Start(processList[i]);
               cout<<"Created PID : "<<PID<<endl;
           }

       }

};



#endif
