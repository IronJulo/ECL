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
            OUTPUT,

            NOT_SET,
        };

        enum class State
        {
            LOW,
            HIGH,

            NOT_SET,
        };

        enum class Resistor
        {
            PULLUP,
            PULLDOWN,
            OPEN_DRAIN,
            ANALOG,

            NOT_SET,
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

            NOT_SET,
        };

        typedef void (*InterruptCallback)(void);
    } // namespace Gpio

    class AbstractGpio
    {
    private:
        Gpio::InterruptCallback m_callback = nullptr;
        Gpio::InterruptEdge m_interruptEdge = Gpio::InterruptEdge::NOT_SET;
        Gpio::Direction m_direction = Gpio::Direction::NOT_SET;
        Gpio::Resistor m_resistor = Gpio::Resistor::NOT_SET;
        Gpio::State m_state = Gpio::State::NOT_SET;

    public:
        AbstractGpio() = default;
        virtual ~AbstractGpio() = default;

        virtual void setDirection(Gpio::Direction direction) { m_direction = direction; }
        virtual void setResistor(Gpio::Resistor resistor) { m_resistor = resistor; }
        virtual void setState(Gpio::State state) { m_state = state; }
        virtual Gpio::State getState() { return m_state; }

        virtual void configureInterrupt(Gpio::InterruptEdge edge, Gpio::InterruptCallback callback)
        {
            m_interruptEdge = edge;
            m_callback = callback;
        };
    };
} // namespace ecl

#endif /* ECL_ABSTRACT_GPIO_H */