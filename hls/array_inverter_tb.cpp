#include <iostream>
#include <stdint.h>

#define DATA_SIZE 100

// Prototype for the DUT (Design Under Test)
void array_inverter(volatile int in1[DATA_SIZE], volatile int out[DATA_SIZE]);

// Helper function to print arrays with a line break every 10 elements
void print_array(const int arr[DATA_SIZE], const std::string& label) {
    std::cout << "\n" << label << ":\n[ ";
    for (int i = 0; i < DATA_SIZE; i++) {
        std::cout << arr[i];
        if (i != DATA_SIZE - 1) {
            std::cout << ", ";  // Add comma only if not the last element
        }
        if ((i + 1) % 10 == 0 && i != DATA_SIZE - 1) {
            std::cout << std::endl << "  ";  // Indent subsequent lines for readability
        }
    }
    std::cout << " ]\n" << std::endl;
}

int main() {
    std::cout << "\n\n========================================\n\n" << std::endl;
    std::cout << "Initializing Array Inverter test bench." << std::endl;

    int in1[DATA_SIZE];
    int out[DATA_SIZE];
    int expected_out[DATA_SIZE];

    // Initialize input array with values from 1 to DATA_SIZE
    std::cout << "Initializing input array with values from 1 to " << DATA_SIZE << "." << std::endl;
    for (int i = 0; i < DATA_SIZE; i++) {
        in1[i] = i + 1;
    }
    print_array(in1, "Input array");

    // Compute expected output array by reversing in1
    std::cout << "Manually computing expected output array." << std::endl;
    for (int i = 0; i < DATA_SIZE; i++) {
        expected_out[i] = in1[DATA_SIZE - 1 - i];
    }
    print_array(expected_out, "Expected output array");

    // Call the DUT to compute the actual output
    std::cout << "Calling array_inverter to compute actual output array." << std::endl;
    array_inverter(in1, out);
    print_array(out, "Output array");

    // Verify the output array against the expected values
    std::cout << "Verifying inverted output array." << std::endl;
    bool pass = true;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (out[i] != expected_out[i]) {
            std::cout << "Test failed at index " << i
                      << ": expected " << expected_out[i]
                      << ", but got " << out[i] << std::endl;
            pass = false;
            break;
        }
    }

    if (pass) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    std::cout << "\n\n========================================\n\n" << std::endl;

    return pass ? 0 : 1;
}
