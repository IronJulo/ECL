/**
 * @file AbstractSPI.h
 * @brief Abstract interface for SPI communication in Embedded Core Library (ECL).
 *
 * Provides an abstract base class for Serial Peripheral Interface (SPI) communication.
 * This interface defines essential operations such as reading and writing bytes,
 * 16-bit, and 32-bit data, as well as reading and writing arrays of bytes. Implementations
 * of this interface should provide the specific mechanisms for SPI transactions
 * according to the underlying hardware platform. This abstraction allows for easy
 * integration and swapping of different SPI devices.
 * 
 * @author Jules Brossier
 * @date 2024-02-15
 */

#ifndef ECL_ABSTRACT_SPI_H
#define ECL_ABSTRACT_SPI_H

#include <stdint.h>

namespace ecl
{
    class AbstractSPI
    {
    public:
        AbstractSPI() = default;
        virtual ~AbstractSPI() = default;

        virtual uint8_t read() = 0;
        virtual uint16_t read16() = 0;
        virtual uint32_t read32() = 0;
        /**
         * @brief Reads a sequence of bytes from SPI into a provided buffer.
         * @param[out] data Pointer to the buffer where read bytes will be stored.
         * @param[in,out] size On input, specifies the size of the buffer (maximum number of bytes to read).
         *                     On return, it will contain the actual number of bytes read.
         */
        virtual void readBytes(uint8_t *data, uint32_t &size) = 0;
        
        virtual void write(uint8_t data) = 0;
        virtual void write16(uint16_t data) = 0;
        virtual void write32(uint32_t data) = 0;
        /**
         * @brief Writes a sequence of bytes to SPI from a provided buffer.
         * @param[in] data Pointer to the buffer containing the bytes to be written.
         * @param[in,out] size On input, specifies the number of bytes to write.
         *                     On return, it will contain the actual number of bytes written.
         */
        virtual void writeBytes(const uint8_t * data, uint32_t &size) = 0;
    };
    
} // namespace ecl


#endif /* ECL_ABSTRACT_SPI_H */