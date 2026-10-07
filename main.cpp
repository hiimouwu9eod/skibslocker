#include <iostream>
#include <iomanip>
#include "offsets.hpp"

int main() {
    std::cout << "skibslocker" << std::endl;
    std::cout << "ClientVersion: " << Offsets::ClientVersion << std::endl;
    std::cout << std::hex << std::showbase;
    std::cout << "FakeDataModel::Pointer = " << Offsets::FakeDataModel::Pointer << std::endl;
    std::cout << "TaskScheduler::Pointer = " << Offsets::TaskScheduler::Pointer << std::endl;
    std::cout << "VisualEngine::Pointer = " << Offsets::VisualEngine::Pointer << std::endl;
    std::cout << "Humanoid::HumanoidRootPart = " << Offsets::Humanoid::HumanoidRootPart << std::endl;
    std::cout << "Humanoid::Walkspeed = " << Offsets::Humanoid::Walkspeed << std::endl;
    return 0;
}
