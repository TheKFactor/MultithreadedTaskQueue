// MultithreadedTaskQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::queue<int> taskQueue;
std::mutex queueMutex;

void worker(int id) {
    while (true) {
        int task = -1;

        {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (!taskQueue.empty()) {
                task = taskQueue.front();
                taskQueue.pop();
            }
            else {
                break; // Exit if no more tasks
            }
        }

        std::cout << "Worker " << id << " is processing task " << task << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
    }
}

int main() {
    for (int i = 1; i <= 10; ++i) {
        taskQueue.push(i);
    }

    std::vector<std::thread> workers;
    for (int i = 1; i <= 3; ++i) {
        workers.push_back(std::thread(worker, i));
    }

    for (auto& t : workers) {
        t.join();
    }

    std::cout << "All tasks completed!" << std::endl;
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
