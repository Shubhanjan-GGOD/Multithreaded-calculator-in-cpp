#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <unordered_map>

// Mutex for thread safety
std::mutex mtx;

// Template function for calculations
template <typename T>
T calculate(char op, T a, T b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            throw std::runtime_error("Division by zero!");
        default:
            throw std::invalid_argument("Invalid operator!");
    }
}

// Function to run calculation asynchronously
template <typename T>
void async_calculate(char op, T a, T b) {
    try {
        // Launch async task
        std::future<T> result_future = std::async(std::launch::async, calculate<T>, op, a, b);
        T result = result_future.get();  // Get result

        // Thread-safe output
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Result (" << typeid(T).name() << "): " << a << " " << op << " " << b << " = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    char op;
    double num1, num2;

    // Take user input
    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Run calculation in a separate thread
    std::thread calc_thread(async_calculate<double>, op, num1, num2);
    calc_thread.join();  // Wait for thread to finish

    return 0;
}

