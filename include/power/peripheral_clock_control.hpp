#ifndef MHAA_POWER_PERIPHERAL_CLOCK_CONTROL_HPP
#define MHAA_POWER_PERIPHERAL_CLOCK_CONTROL_HPP

#include <power/types.hpp>

namespace mhaa
{
    namespace power
    {
        /** @brief Controls clocks for logical peripheral resources. */
        class PeripheralClockControl
        {
        public:
            virtual ~PeripheralClockControl() = default;
            virtual Status set_enabled(PeripheralId peripheral, bool enabled) = 0;
        };
    }
}

#endif
