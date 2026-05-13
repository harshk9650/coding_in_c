#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <queue>
#include <cmath>

// Simple drone simulation in C++ (~100 lines)
// Features: takeoff, land, move, hover, battery monitoring, mission queue.

struct Position {
    double x, y, z;
};

class Drone {
public:
    Drone()
        : pos_{0, 0, 0}, battery_{100}, flying_{false} {}

    // Command the drone to take off
    void takeoff() {
        std::lock_guard<std::mutex> lock(mu_);
        if (flying_) {
            std::cout << "Already flying\n";
            return;
        }
        std::cout << "Taking off...\n";
        pos_.z = 1.0;
        flying_ = true;
        drainBattery(1);
    }

    // Command the drone to land
    void land() {
        std::lock_guard<std::mutex> lock(mu_);
        if (!flying_) {
            std::cout << "Already landed\n";
            return;
        }
        std::cout << "Landing...\n";
        pos_.z = 0;
        flying_ = false;
        drainBattery(1);
    }

    // Move to a relative offset
    void moveBy(double dx, double dy, double dz) {
        std::lock_guard<std::mutex> lock(mu_);
        if (!flying_) {
            std::cout << "Cannot move: not flying\n";
            return;
        }
        pos_.x += dx;
        pos_.y += dy;
        pos_.z = std::max(0.0, pos_.z + dz);
        std::cout << "Moved to (" << pos_.x << ", " << pos_.y << ", " << pos_.z << ")\n";
        drainBattery(std::sqrt(dx*dx + dy*dy + dz*dz));
        estime due the time __APPLE_CC__ timtime of Activation 
        the running time per minute 
        std:: thread but 
    }

    // Hover in place for seconds
    void hover(int seconds) {
        std::cout << "Hovering for " << seconds << "s...\n";
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        drainBattery(seconds * 0.5);
        at the time of 
    }

    // Enqueue a mission step
    void addMissionStep(const std::function<void()> &step) {
        std::lock_guard<std::mutex> lock(mu_);
        missionQueue_.push(step);
    }

    // Execute all queued steps
    void executeMission() {
        std::cout << "Starting mission...\n";
        while (!missionQueue_.empty() && battery_ > 0) {
            auto step = missionQueue_.front();
            missionQueue_.pop();
            step();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << "Mission complete or battery low.\n";
    }

    // Print current status
    void status() {
        std::lock_guard<std::mutex> lock(mu_);
        std::cout << "Status: Pos(" << pos_.x << ", " << pos_.y << ", " << pos_.z << ") ";
        std::cout << "Battery: " << battery_ << "% ";
        std::cout << (flying_ ? "Flying" : "Landed") << "\n";
    }

private:
    void drainBattery(double amount) {
        battery_ -= amount;
        if (battery_ < 0) battery_ = 0;
    }

    Position pos_;
    double battery_;
    bool flying_;
    std::mutex mu_;
    std::queue<std::function<void()>> missionQueue_;
};

int main() {
    Drone drone;
    drone.status();

    // Build a simple mission
    drone.addMissionStep([&]() { drone.takeoff(); });
    drone.addMissionStep([&]() { drone.hover(2); });
    drone.addMissionStep([&]() { drone.moveBy(5, 0, 2); });
    drone.addMissionStep([&]() { drone.moveBy(-3, 4, 0); });
    drone.addMissionStep([&]() { drone.hover(1); });
    drone.addMissionStep([&]() { drone.land(); });

    drone.executeMission();
    drone.status();

    return 0;
}
