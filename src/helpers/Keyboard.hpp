#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <thread>
#include <atomic>

class Keyboard
{
private:
    std::atomic<bool> isRunning;
    int keyPressed;

    std::thread thread;

    void readKeyPress();

public:
    Keyboard();
    ~Keyboard();

    int getKeyPressed();
};

#endif
