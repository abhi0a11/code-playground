#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

void taskA() {
    for (int i = 0; i < 7; i++) {
        sleep(1);
        printf("taskA %d\n", i);
        fflush(stdout);
    }
}

void taskB() {
    for (int i = 0; i < 7; i++) {
        sleep(1);
        printf("taskB %d\n", i);
        fflush(stdout);
    }
}


int main() {
    thread t1(taskA), t2(taskB);

    t1.join();
    t2.join();
    return 0;
}