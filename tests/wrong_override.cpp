#include <power/sleep_controller.hpp>

using namespace mhaa::power;

class WrongOverride final : public SleepController
{
public:
    Status enter(SleepMode mode) const override;
};
