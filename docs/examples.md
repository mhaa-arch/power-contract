# Power Management Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The sleep fake accepts idle and rejects deep sleep. A separate gate fake rejects an unknown ID, preserves its original state on rejection and applies a change to its known ID. The two objects illustrate that implementations can supply either capability independently.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <power/sleep_controller.hpp>
#include <power/peripheral_clock_control.hpp>


using namespace mhaa::power;

class FakeSleep final : public SleepController
{
public:
    Status enter(SleepMode mode) override
    {
        return mode == SleepMode::Idle ? Status::Success : Status::Unsupported;
    }
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
