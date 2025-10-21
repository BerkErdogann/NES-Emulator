#pragma once
#include <vector>
#include <cstdint>


using Byte = std::uint8_t;
using TwoByte = std::uint16_t;
using EffectiveAddress = std::uint16_t;

class CPU
{
    


private:
    
    std::vector<Byte> romData {};
    Byte ram[0x0800] {};
    TwoByte pc {};
    Byte ac {};
    Byte x {};
    Byte y {};
    Byte sr{};
    Byte sp{0xFD};

    inline static constexpr Byte carryFlag {1};
    inline static constexpr Byte zeroFlag {1 << 1};
    inline static constexpr Byte decimalFlag {1 << 2};
    inline static constexpr Byte breakFlag {1 << 3};
    inline static constexpr Byte interruptFlag {1 << 4};
    inline static constexpr Byte ignored {1 << 5};
    inline static constexpr Byte overflowFlag {1 << 6};
    inline static constexpr Byte negativeFlag {1 << 7};


    void setZeroNegativeFlag(Byte value);
    void setCarryFlag(bool carry);
    void setOverFlowFlag(Byte op1, Byte op2, Byte result);

    Byte read(TwoByte addr);
    void write(TwoByte addr, Byte value);
    void step();

    //  Address Modes
    Byte immediate();
    EffectiveAddress zeroPage();
    EffectiveAddress zeroPageX();
    EffectiveAddress zeroPageY();
    EffectiveAddress absolute();
    EffectiveAddress absoluteX();
    EffectiveAddress absoluteY();
    EffectiveAddress indirect();
    EffectiveAddress indirectX();
    EffectiveAddress indirectY();
    EffectiveAddress relative();
    
    //  Address Modes
    

public:
    CPU(std::vector<uint8_t>&& rom);
};