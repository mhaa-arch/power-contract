# Power Management contract

## Sleep categories

[SleepController](../include/power/sleep_controller.hpp) accepts a supported `SleepMode`. Idle allows execution to pause with ordinary peripheral clocks available. Standby permits additional gating while retaining context. Deep sleep can require restart instead of returning to the caller if the Adapter documents that behavior. A sleep request can block until a wake event or return `Busy`, `Unsupported` or `Error`.

## Clock gating

[PeripheralClockControl](../include/power/peripheral_clock_control.hpp) applies enable or disable to a logical `PeripheralId` assigned by composition. Unknown IDs return `InvalidPeripheral`. Success means the requested gate state was applied. Specify dependencies such as shared gates and which users must release the peripheral before gating it.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`power/types.hpp`](../include/power/types.hpp).
