#ifndef SPAWNHANDLER
#define SPAWNHANDLER

#include <spawn.h>
#include <sys/wait.h>

using namespace std;
class SpawnHandler
{
    public:
        
        int Start(string PName )
        {
            int pid = 0;

            int error = posix_spawn(&pid, PName.c_str(), NULL, NULL, NULL, NULL);

            cout<<"Error::"<<error <<endl;
            if(!error)
                cout<<"SucessFull Process "<<PName<<" Creation PID:"<<pid<<endl;
            else
                cout<<"Bad Case::"<<endl;
            
            /* P1 Process Fork is success but exec is failed. Thus the process gets created 
               but it does get any binary to execute {Actually failed for us}. Hence return value will be 0 as success.
               Inorder to confirm the child process exit status use waitpid and WEXITSTATUS.
               */
            int status = 0;
            waitpid(pid, &status, 0);
            cout << "raki: Process "<<status<<endl;
            status = WEXITSTATUS(status);  // Takes care of little endian and big endian stuff and gives correct status.
            cout << "raki: 2Process "<<status<<endl;
            if (status == 127) // P1 case.
                cout << "Process "<<PName<<" failed"<<endl;
            return pid;

        }

};



#endif
