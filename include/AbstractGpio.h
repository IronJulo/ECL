#ifndef ECL_ABSTRACT_GPIO_H
#define ECL_ABSTRACT_GPIO_H

#include <stdint.h>

namespace ecl
{

    namespace Gpio
    {
        enum class Direction
        {
            INPUT,
            OUTPUT
        };

        enum class State
        {
            LOW,
            HIGH
        };

        enum class Resistor
        {
            PULLUP,
            PULLDOWN,
            OPEN_DRAIN,
            ANALOG,
        };

        enum class InterruptEdge
        {
            RISING,
            FALLING,
            CHANGE,
            ONLOW,
            ONHIGH,
            ONLOW_WE,
            ONHIGH_WE,
        };

        typedef void (*InterruptCallback)(void);
    } // namespace Gpio

    class AbstractGpio
    {
    private:
        Gpio::InterruptCallback m_callback = nullptr;

    public:
        AbstractGpio() = default;
        virtual ~AbstractGpio() = default;

        virtual void setDirection(Gpio::Direction direction) = 0;
        virtual void setResistor(Gpio::Resistor resistor) = 0;
        virtual void setState(Gpio::State state) = 0;
        virtual Gpio::State getState() = 0;

        virtual void configureInterrupt(Gpio::InterruptEdge edge, Gpio::InterruptCallback callback) = 0;
    };
} // namespace ecl

#endif /* ECL_ABSTRACT_GPIO_H */