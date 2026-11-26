#ifndef MHAA_POWER_TYPES_HPP
#define MHAA_POWER_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace power
    {
        enum class SleepMode
        {
            Idle,
            Standby,
            DeepSleep
        };

        enum class PeripheralId : uint16_t
        {
        };
        
        enum class Status
        {
            Success,
            Busy,
            InvalidArgument,
            InvalidPeripheral,
            Unsupported,
            Error
        };
    }
}

#endif
