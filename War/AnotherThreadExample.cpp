#include <string>
#include <iostream>
#include <thread>
#include <dos.h>
#include<conio.h>
using namespace std;

// The function we want to execute on the new thread.
void task1(string msg)
{
	for (int i = 0; i<100; i++){
		cout << "\ntask1 says: " << msg;
	}
    
}

void task2(string msg)
{
    for (int i = 0; i<100; i++){
		cout << "\ntask2 says: " << msg;
	}
}

int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(task1, "Hello");
	thread t2(task2, "Pvto Memo");
    // Do other things...

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
    t2.join();
}
