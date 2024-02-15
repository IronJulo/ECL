#ifndef ECL_TRANSPORT_H
#define ECL_TRANSPORT_H

#include <stdint.h>
#include "Endianness.h"

namespace ecl
{
    class Transport
    {
    private:
        Endianness m_endianness;

    public:
        Transport(Endianness endianness) : m_endianness(endianness) {}
        virtual ~Transport() = default;
        
        virtual bool start() = 0;
        virtual bool finish() = 0;

    public:
        virtual void write(uint8_t data) = 0;
        virtual void write16(uint16_t data) = 0;
        virtual void write32(uint32_t data) = 0;
        virtual void write64(uint64_t data) = 0;
        virtual void write(const uint8_t *data, uint16_t &size) = 0;

        virtual uint8_t read() = 0;
        virtual uint16_t read16() = 0;
        virtual uint32_t read32() = 0;
        virtual uint64_t read64() = 0;
        virtual void read(uint8_t *data, uint16_t &size) = 0;
    };
} // namespace ecl

#endif /* ECL_TRANSPORT_H */