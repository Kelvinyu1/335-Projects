#include <iostream>

int main() {
      // Assume newOwnerPtr already points to some allocated memory
      int* newOwnerPtr = new int[3] {10, 20, 30}; // Initially owned memory

      // Original pointer allocation
      int* originalPtr = new int[5] {1, 2, 3, 4, 5};  // Dynamically allocated array

      // Before moving ownership, delete the memory newOwnerPtr currently owns
      delete[] newOwnerPtr;

      // Move ownership from originalPtr to newOwnerPtr
      newOwnerPtr = originalPtr;
      originalPtr = nullptr;  // Ensure the original pointer does not dangle

      // Use the newOwnerPtr...
      for (int i = 0; i < 5; ++i) {
            std::cout << newOwnerPtr[i] << " ";
        }
      std::cout << std::endl;

      // Once you're done using newOwnerPtr, delete the memory
      delete[] newOwnerPtr;
      newOwnerPtr = nullptr;  // Prevent dangling pointer

      return 0;
  }

