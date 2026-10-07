#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace injector {

// Find all running Roblox client PIDs (RobloxPlayerBeta.exe).
std::vector<uint32_t> FindRobloxProcesses();

// Injects dllPath into pid via LoadLibraryW remote thread.
// Returns true on success, false on failure with human-readable error.
bool InjectDll(uint32_t pid, const std::wstring& dllPath, std::wstring& error);

std::wstring StrError(uint32_t code);

} // namespace injector
