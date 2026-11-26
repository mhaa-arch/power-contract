#ifndef MHAA_POWER_SLEEP_CONTROLLER_HPP
#define MHAA_POWER_SLEEP_CONTROLLER_HPP

#include <power/types.hpp>

namespace mhaa
{
    namespace power
    {
        /** @brief Requests a supported sleep category in the current context. */
        class SleepController
        {
        public:
            virtual ~SleepController() = default;

            /** @brief May suspend execution until a wake event. */
            virtual Status enter(SleepMode mode) = 0;
        };
    }
}

#endif
