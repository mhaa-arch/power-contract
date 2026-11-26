#include <power/sleep_controller.hpp>

using namespace mhaa::power;

class Incomplete final : public SleepController
{
public:
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
