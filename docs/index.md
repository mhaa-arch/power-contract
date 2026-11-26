# Power Management Contract guide

Sleep and peripheral clock gating have separate effects and use separate resource interfaces. Choose the sleep or clock-gating path and check target-specific wake and dependency requirements.

1. Start with [the contract](contract.md) for implementer obligations and capability boundaries.
2. Read [the conformance example](examples.md) for an implementation you can compile locally.
3. Consult [the portability notes](compatibility.md) before choosing a hardware mapping.