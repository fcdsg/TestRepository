#include <iostream>
#include "robot.h"
#include "test.h"

int main() {
    Test test;
    test.doSomething();

    FRRobot robot;
    char version[100];
    robot.GetSDKVersion(version);
    std::cout << "SDK Version: " << version << std::endl;


    return 0;
}