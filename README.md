# Multithreaded Task Queue 🚀

A multithreaded task queue system built in C++ using `std::thread` and `std::mutex` to simulate real-time task handling with multiple worker threads.

## 🧠 Features

- Thread-safe task queue using mutex locking
- Multiple worker threads processing tasks in parallel
- Real-time task simulation using `std::this_thread::sleep_for`
- Demonstrates concepts of concurrency and parallelism in modern C++

## 🛠️ Technologies Used

- C++
- STL (`thread`, `mutex`, `queue`, `chrono`)
- Visual Studio 2022

## 📸 Screenshot 

![Task Queue Screenshot](https://github.com/TheKFactor/MultithreadedTaskQueue/blob/main/screenshot(101).png)


## 🚀 How to Run

1. Clone this repository  
   ```bash
   git clone https://github.com/YOUR_USERNAME/MultithreadedTaskQueue.git
2. Compile the code:
   g++ main.cpp -o task_queue -pthread
3. Run:
   ./task_queue
