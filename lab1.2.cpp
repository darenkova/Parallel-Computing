#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void printnum(int n) {
    for (size_t i = 0; i < 6; i++) {
        cout << "поток: " << n << " " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main() {
    setlocale(LC_ALL, "");

    thread t1([]() { printnum(1); });
    thread t2([]() { printnum(2); });

    for (size_t i = 0; i < 6; i++) {
        cout << " Основной поток" << " " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    t1.join();
    t2.detach();

    this_thread::sleep_for(chrono::milliseconds(2000));
    return 0;
}