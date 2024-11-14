#include<bits/stdc++.h>
using namespace std;
class SingleTon {
private:
    // static so that they can be initiasied only once at the time of creation
    static SingleTon* instance;
    static mutex mtx;
    // private constructor so that object cannot be created outside the class
    SingleTon() {}
public:
    SingleTon(SingleTon& obj) = delete;
    void operator=(const SingleTon&) = delete;

    static SingleTon* getInstance() {

        /*
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new SingleTon();
            }

            The only downside to the above solution is that it may be expensive. Each access to the Singleton requires the acquisition of a lock, but in reality, we need a lock only when initialising instance. That should occur only the first time instance is called. If instance is called n times during the course of a program run, we need the lock only for the ﬁrst call. Why pay for n lock acquisitions when you know that n − 1 of them are unnecessary? DCLP is designed to prevent you from having to. [1]
        */
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx); // thread safe singletom implementation
            if (instance == nullptr) {
                instance = new SingleTon();
            }
        }
        return instance;
    }
};

// initialise static member
SingleTon* SingleTon::instance = nullptr;
mutex SingleTon::mtx;

int main() {
    // getInstance() => request's instance from the class if it exist otherwise create the instance.
    SingleTon* s1 = SingleTon::getInstance();

    return 0;
}