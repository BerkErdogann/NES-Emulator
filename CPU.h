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