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

        ~Transaction()
        {
            this->finish();
        }
        operator bool() const { return m_state; }

    private:
        inline bool start() { return this->m_transport.lock(); }
        inline bool finish() { return this->m_transport.unlock(); }

    public:
        inline void write(uint8_t data) { this->m_transport.write(data); }
        inline uint8_t read() { return this->m_transport.read(); }
        inline uint8_t transfer(uint8_t data) { return this->m_transport.transfer(data); }
    };
} // namespace ecl

#endif /* ECL_TRANSACTION_H */