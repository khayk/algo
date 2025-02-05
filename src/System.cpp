#ifdef _WIN32
  // Platform dependent include files
  #include <Windows.h>
  #include <Psapi.h>
#else
  #include <pwd.h>
  #include <unistd.h>

  #include <fstream>
  #include <sstream>
#endif

#include "System.h"

namespace sys {

uint32_t currentProcessId() noexcept {
#ifdef _WIN32
  return GetCurrentProcessId();
#else
  return getpid();
#endif  // _WIN32
}

size_t processMemoryUsage(uint32_t pid) noexcept {
#ifdef _WIN32
  HANDLE process = nullptr;
  PROCESS_MEMORY_COUNTERS pmc{};

  process =
      OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
  if (nullptr == process) {
    return 0;
  }

  auto sg = alg::makeScopeGuard([&process]() { CloseHandle(process); });

  if (!GetProcessMemoryInfo(process, &pmc, sizeof(pmc))) {
    return 0;
  }

  return pmc.WorkingSetSize;
#else
  std::string filename = "/proc/" + std::to_string(pid) + "/status";
  std::ifstream file(filename, std::ios::in);

  if (!file.is_open()) {
    return 0;
  }

  std::string line;
  long memory = -1;
  while (getline(file, line)) {
    if (line.find("VmRSS:") == 0) {
      std::istringstream iss(line);
      std::string label;
      iss >> label >> memory;
      break;
    }
  }

  return memory * 1024;
#endif
}

size_t currentProcessMemoryUsage() noexcept {
  return processMemoryUsage(currentProcessId());
}

}  // namespace sys
