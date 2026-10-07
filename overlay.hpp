#pragma once
#include <cstdint>
#include <string>

namespace overlay {

// Transparent fullscreen ESP overlay driven by esp::g toggles.
// Start attaches to pid and spawns the render thread; Stop joins it.
bool Start(uint32_t pid, std::wstring& error);
void Stop();
bool Running();
// One-line status for the UI (player count / last error).
std::wstring Status();

} // namespace overlay
