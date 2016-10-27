#pragma once
#include <thread>
#include <stdexcept>

class scoped_thread {
    std::thread t;
public:
    explicit scoped_thread(std::thread t) :
    t(std::move(t)) {
        if(!t.joinable()) {
            throw std::logic_error("No thread");
        }
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread &) = delete;
    scoped_thread& operator=(const scoped_thread &) = delete;
};

/*
int main() {
    scoped_thread t(std::thread(do_stuff));
    return 0;
}
 */