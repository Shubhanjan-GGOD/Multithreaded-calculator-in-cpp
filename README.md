# Multithreaded-calculator-in-cpp
This project is a simple calculator built using C++ concurrency features such as std::thread, std::async, and std::mutex. It performs basic arithmetic operations asynchronously and ensures thread safety using a mutex.


Features -
1.Supports addition, subtraction, multiplication, and division
2. Uses multithreading for asynchronous calculations
3. Ensures thread safety with std::mutex
4. Works with different data types using C++ templates

How It Works -
The user provides two numbers and an operator (+, -, *, /).

The computation is performed asynchronously using std::async.

A mutex (std::mutex) ensures safe access to shared resources.

The result is printed in a thread-safe manner.




