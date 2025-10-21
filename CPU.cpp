#include "CPU.h"

Byte CPU::read(TwoByte addr)
{
    if (addr <= 0x1FFF)         // Read from RAM
    {
        return ram[addr % 0x0800];
    }
    else if (addr >= 0x8000)    // Read from ROM
    {
        return romData[addr - 0x8000];
    }
}

void CPU::write(TwoByte addr, Byte value)
{
    if (addr <= 0x1FFF)         // Write to RAM
    {
        ram[addr % 0x0800] = value;
    }
}

void CPU::step()
{

     

}

Byte CPU::immediate()
{
    return read(pc++);
}

CPU::CPU(std::vector<uint8_t> &&rom) : romData{std::move(rom)}
{
    pc = (romData[0xFFFD] << 8) | romData[0x00FFC];
}


