#ifndef ECL_ABSTRACT_GPIO_H
#define ECL_ABSTRACT_GPIO_H

#include <stdint.h>

namespace ecl
{

    namespace Gpio
    {
        enum class Direction
        {
            Input,
            Output,

            NotSet,
        };

        enum class State
        {
            Low,
            High,

            NotSet,
        };

        enum class Resistor
        {
            PullUp,
            PullDown,
            OpenDrain,
            Analog,

            NotSet,
        };

        enum class InterruptEdge
        {
            Rising,
            Falling,
            Change,
            OnLow,
            OnHigh,
            OnLowWe,
            OnHighWe,

            NotSet,
        };

        typedef void (*InterruptCallback)(void);
    } // namespace Gpio

    class AbstractGpio
    {
    private:
        Gpio::InterruptCallback m_callback = nullptr;
        Gpio::InterruptEdge m_interruptEdge = Gpio::InterruptEdge::NotSet;
        Gpio::Direction m_direction = Gpio::Direction::NotSet;
        Gpio::Resistor m_resistor = Gpio::Resistor::NotSet;
        Gpio::State m_state = Gpio::State::NotSet;

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