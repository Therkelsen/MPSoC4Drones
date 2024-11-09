#include <stdio.h>
#include <assert.h>

// Define DATA_SIZE for testing
#define DATA_SIZE 100

// Example software function that mimics the IP logic (can be replaced by real logic)
void array_inverter_sw(int in1[DATA_SIZE], int out[DATA_SIZE]) {
    for (int i = 0; i < DATA_SIZE; i++) {
        out[i] = in1[DATA_SIZE - 1 - i];
    }
}

// Helper function to print arrays with a line break every 10 elements
void print_array(const int arr[DATA_SIZE], const char *label) {
    printf("\n%s:\n[ ", label);
    for (int i = 0; i < DATA_SIZE; i++) {
        printf("%d", arr[i]);
        if (i != DATA_SIZE - 1) {
            printf(", ");
        }
        if ((i + 1) % 10 == 0 && i != DATA_SIZE - 1) {
            printf("\n  ");
        }
    }
    printf(" ]\n\n");
}

// Test function to check if the array inversion works correctly
void test_array_inversion() {
    int in1[DATA_SIZE], out[DATA_SIZE], expected_out[DATA_SIZE];

    // Initialize the input array with known values
    printf("Initializing input array with values from 1 to %d.\n", DATA_SIZE);
    for (int i = 0; i < DATA_SIZE; i++) {
        in1[i] = i + 1;  // Example: in1 = [1, 2, 3, ..., 100]
    }
    print_array(in1, "Input array");

    // Expected output is the reverse of the input array
    printf("Manually computing expected output array by reversing the input.\n");
    for (int i = 0; i < DATA_SIZE; i++) {
        expected_out[i] = in1[DATA_SIZE - 1 - i];  // Expected out = [100, 99, ..., 1]
    }
    print_array(expected_out, "Expected output array");

    // Call your array inversion logic (this could be a software function or your IP)
    printf("Calling array_inverter_sw to compute actual output array.\n");
    array_inverter_sw(in1, out);
    print_array(out, "Actual output array");

    // Compare output to expected output
    printf("Verifying output array against expected output.\n");
    bool pass = true;
    for (int i = 0; i < DATA_SIZE; i++) {
        if (out[i] != expected_out[i]) {
            printf("Test failed at index %d: expected %d, but got %d\n", i, expected_out[i], out[i]);
            pass = false;
            break;
        }
    }

    if (pass) {
        printf("Test passed: Array inversion logic is correct.\n");
    } else {
        printf("Test failed.\n");
    }
}

int main() {
    printf("\n\n========================================\n\n");
    printf("Initializing Array Inverter Unit Test\n");

    // Run unit test
    test_array_inversion();

    // If no assertion failed, print success message
    printf("\n\n========================================\n\n");

    return 0;
}
