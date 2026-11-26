# Porting the Power Management Contract

Hardware Definitions can describe supported physical power states, wake sources and gate topology. The Adapter maps available modes to the common categories and reports when retention, wake or gate requirements cannot be satisfied. An enabled gate does not by itself initialize a peripheral. Sleep support neither requires nor implies independently exposed gating.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
