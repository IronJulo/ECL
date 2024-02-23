#ifndef ECL_TRANSPORT_H
#define ECL_TRANSPORT_H

#include <stdint.h>
#include "Endianness.h"

namespace ecl
{
    class Transaction;
    class Transport
    {
    private:
        Endianness m_endianness;

    public:
        Transport(Endianness endianness) : m_endianness(endianness) {}
        virtual ~Transport() = default;

        virtual bool lock() = 0;
        virtual bool unLock() = 0;

    public:
        virtual void write(uint8_t data) = 0;
        virtual uint8_t read() = 0;
        virtual uint8_t transfer(uint8_t data) = 0;
        virtual void begin() = 0;

        virtual Transaction startTransaction() = 0;
    };
} // namespace ecl

#endif /* ECL_TRANSPORT_H */