#ifndef ECL_TRANSACTION_H
#define ECL_TRANSACTION_H

#include <stdint.h>
#include "Endianness.h"
#include "Transport.h"

namespace ecl
{
    class Transaction
    {
    private:
        Transport &m_transport;
        bool m_state;

    public:
        Transaction(Transport &transport) : m_transport(transport)
        {
            m_state = this->start();
        }
        /**
         * When the object is deleted release the transaction eg: liberate i2c lines / release cs for SPI, ...
        */
        ~Transaction() 
        {
            this->finish();
        }
        operator bool() const { return m_state; }

    private:
        inline bool start() { return this->m_transport.start(); }
        inline bool finish() { return this->m_transport.finish(); }

    public:
        inline void write(uint8_t data) { this->m_transport.write(data); }
        inline void write16(uint16_t data) { this->m_transport.write16(data); }
        inline void write32(uint32_t data) { this->m_transport.write32(data); }
        inline void write64(uint64_t data) { this->m_transport.write64(data); }
        inline void write(const uint8_t *data, uint16_t &size) { this->m_transport.write(data, size); }

        inline uint8_t read() { return this->m_transport.read(); }
        inline uint16_t read16() { return this->m_transport.read16(); }
        inline uint32_t read32() { return this->m_transport.read32(); }
        inline uint64_t read64() { return this->m_transport.read64(); }
        inline void read(uint8_t *data, uint16_t &size) { this->m_transport.read(data, size); }
    };
} // namespace ecl

#endif /* ECL_TRANSACTION_H */