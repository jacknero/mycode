#include<iostream>
#include<GetPot>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>


using namespace std;

extern "C" {
#include<math.h>
}
void print_help();

int
main(int argc, char** argv)
{
    using namespace std;

    GetPot      cl(argc, argv);
    string      base_directory = cl.follow("./", "--directory");

    if( cl.search(1, "--hwut-info") ) { 
        cout << "Bug:  <Volker Mertens> 2026390 Hangup in Input File Parsing\n";
        return 0;
    }

    pid_t  test_pid  = (pid_t)0;

    if( ! (test_pid = fork()) ) {
        // child
        GetPot      cf((base_directory + "bug-2026390.pot").c_str());      
        cf.print();    
    } else { 
        // parent: 
        sleep(3);  
        cout << "Process had 3 seconds time to do its job [exit].\n";
        kill(test_pid, 9);
    }
}

