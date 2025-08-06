#include <cstdint>
#include <iostream>

// Use a macro for the address for clarity and easy modification
#define CAN_STATUS_REGISTER_ADDR 0xAF00

// Assume this is a global volatile pointer to a memory-mapped register
volatile uint8_t *pCanStatusRegister = reinterpret_cast<volatile uint8_t *>(CAN_STATUS_REGISTER_ADDR);

// For testing purposes, we'll simulate the register in memory
uint8_t mockRegister = 0;

void setupMockRegister(uint8_t value)
{
    mockRegister = value;
    pCanStatusRegister = &mockRegister;
}

// Function to check if the bus is off
bool isBusOff()
{
    const uint8_t busOffMask = 1 << 4;
    return (*pCanStatusRegister & busOffMask) != 0;
}

// Function to get the error code
int getErrorCode()
{
    const uint8_t errorCodeMask = (1 << 2) | (1 << 3); // 0b00001100
    uint8_t maskedValue = *pCanStatusRegister & errorCodeMask;
    return maskedValue >> 2; // Shift right by 2 to get the value
}

int main()
{
    // Scenario 1: Bus is off, error code is 1
    // 0b00010100 -> 0x14
    setupMockRegister(0x14);
    std::cout << "Is bus off? " << std::boolalpha << isBusOff() << std::endl; // Should be true
    std::cout << "Error code: " << getErrorCode() << std::endl;               // Should be 1

    // Scenario 2: Bus is on, error code is 3
    // 0b00001111 -> 0x0F
    setupMockRegister(0x0F);
    std::cout << "\nIs bus off? " << std::boolalpha << isBusOff() << std::endl; // Should be false
    std::cout << "Error code: " << getErrorCode() << std::endl;                 // Should be 3
    return 0;
}