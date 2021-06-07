#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex oddevenMu;

condition_variable condVar;

size_t number = 1;

void printEvenOdd(bool isEven, int maxnubmer)
{
    unique_lock<mutex> ul(oddevenMu);
    while (number < maxnubmer)
    {
        condVar.wait(ul, [&]() {return number % 2 == isEven; });
        cout << ::this_thread::get_id() << " " <<number++ << std::endl;
        condVar.notify_all();
    }
}

int main(string args[])
{
    thread oddThread(printEvenOdd, false, 100);
    thread evenThread(printEvenOdd, true, 100);
    oddThread.join();
    evenThread.join();
    return 0;
}