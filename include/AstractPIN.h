#ifndef ECL_ABSTRACT_PIN_H
#define ECL_ABSTRACT_PIN_H

#include <stdint.h>

namespace ecl
{
    class AstractPIN
    {
    public:
        AstractPIN() = default;
        virtual ~AstractPIN() = default;

        virtual void setAsOutput() = 0;
        virtual void write(int value) = 0;
        
        virtual void setAsInput() = 0;
        virtual uint8_t digitalRead() = 0;
    };
} // namespace ecl


#endif /* ECL_ABSTRACT_I2C_H */