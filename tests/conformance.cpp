#include <power/sleep_controller.hpp>
#include <power/peripheral_clock_control.hpp>

#include <cassert>

using namespace mhaa::power;

class FakeSleep final : public SleepController
{
public:
    Status enter(SleepMode mode) override
    {
        return mode == SleepMode::Idle ? Status::Success : Status::Unsupported;
    }
};

class FakeGates final : public PeripheralClockControl
{
public:
    Status set_enabled(PeripheralId peripheral, bool enable) override
    {
        ++calls;
        if (peripheral != PeripheralId{})
        {
            return Status::InvalidPeripheral;
        }
        enabled = enable;
        return Status::Success;
    }

    bool enabled = true;
    unsigned calls = 0;
};

int main()
{
    FakeSleep fake;
    SleepController &sleep = fake;
    assert(sleep.enter(SleepMode::DeepSleep) == Status::Unsupported);
    assert(sleep.enter(SleepMode::Idle) == Status::Success);
    FakeGates fake_gate;
    PeripheralClockControl &gates = fake_gate;
    assert(gates.set_enabled(static_cast<PeripheralId>(2), false) == Status::InvalidPeripheral);
    assert(fake_gate.enabled);
    assert(gates.set_enabled(PeripheralId{}, false) == Status::Success && !fake_gate.enabled);
}
