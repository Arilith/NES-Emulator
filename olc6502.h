//
// Created by Tristan on 09/01/2023.
//

#ifndef NES_OLC6502_H
#define NES_OLC6502_H

#include <cstdint>

class Bus;

class olc6502 {
public:
    olc6502();
    ~olc6502();

public:
    enum FLAGS6502 {
        C = (1 << 0), // Carry Bit
        Z = (1 << 1), // Zero
        I = (1 << 2), // Disable Interrupts
        D = (1 << 3), // Decimal Mode (unused in this implementation)
        B = (1 << 4), // Break
        U = (1 << 5), // Unused
        V = (1 << 6), // Overflow
        N = (1 << 7), // Negative
    };

    uint8_t a = 0x00; // Accumulator
    uint8_t x = 0x00; // X Register
    uint8_t y = 0x00; // Y Register
    uint8_t stkp = 0x00; // Stack Pointer (points to a location on the bus)
    uint16_t pc = 0x0000; // Program Counter
    uint8_t status = 0x00; // Status register


    void ConnectBus(Bus *n) { bus = n; }

private:
    Bus *bus = nullptr;
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t d);

    //Convenience functions to access the status register
};


#endif //NES_OLC6502_H
