#include "Everything.h"
//each module in debug and log get certain parameter(ex: debug(MOUSE_INPUT, mousex, mousey))
//make distance and weight, and volume and velocity measure and convertor as Time
//finish Time
//debugger create debug file then delete it when close program if option set to true
//argc and argv support
//SDL support
//make another type of clock with support for :
/*#include <windows.h>

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main()
{
    StartCounter();
    Sleep(1000);
    cout << GetCounter() <<"\n";
    return 0;
}*/
//Direct X support
//md5 hash support and sha-1 or sha-2 and lose lose and sdbm
//debug encrypted or not(save encryption type unencrypted) if encrypted use binary mode
//encryption system and encrypted file(functions to encrypt passed as parameter(default encryption function)) -> each encrypt has a name
//function get are you sure? yes/no(define wath string in args) with bool -> bool getyn("yes", "no")

int main(int argc, char* argv[])
{
	EVERYTHING.init(EVERYTHING_CONSOLE_MODE);

	while(!EVERYTHING.getQuit()) {
		(EVERYTHING.*EVERYTHING.run)();
	}

	return 0; 
}