#include "CPU.h"


CPU::CPU(std::vector<uint8_t> &&rom) : romData{std::move(rom)}
{
    pc = (romData[0xFFFD] << 8) | romData[0x00FFC];
}

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

EffectiveAddress CPU::zeroPage()
{
    return read(pc++);
}

EffectiveAddress CPU::zeroPageX()
{
    Byte addr { read(pc++) };
    return (addr + x);
}

EffectiveAddress CPU::zeroPageY()
{
    Byte addr { read(pc++) };
    return (addr + y);
}

EffectiveAddress CPU::absolute()
{
    EffectiveAddress addr { read(pc) | ( read(pc + 1) << 8 ) };
    pc += 2;
    return addr;
}

EffectiveAddress CPU::absoluteX()
{
    EffectiveAddress addr { read(pc) | ( read(pc + 1) << 8 ) };
    pc += 2;
    return addr + x;
}

EffectiveAddress CPU::absoluteY()
{
    EffectiveAddress addr { read(pc) | ( read(pc + 1) << 8 ) };
    pc += 2;
    return addr + y;
}

EffectiveAddress CPU::indirect()
{
    EffectiveAddress readAddr { read(pc) | (read(pc + 1) << 8) };
    pc += 2;
    return (read(readAddr) | (read(readAddr + 1) << 8));
}

EffectiveAddress CPU::indirectX()
{
    Byte base { read(pc++) };
    Byte lowBit { read( (base + x) & 0xFF ) }; 
    Byte highBit { read( (base + x + 1) & 0xFF ) };

    return lowBit | (highBit << 8);
}

EffectiveAddress CPU::indirectY()
{
    Byte base { read(pc++) };
    Byte lowBit { read(base)};
    Byte highBit { read( (base + 1) & 0xFF )  };

    return (lowBit | (highBit << 8)) + y;
}

EffectiveAddress CPU::relative()
{
    std::int8_t offset { read(pc++) };
    return pc + offset;
}
