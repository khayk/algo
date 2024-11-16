#ifdef _WIN32
  // Platform dependent include files
  #include <Windows.h>
  #include <Psapi.h>
#else
  #include <pwd.h>
#endif

#include "System.h"
#include "Utils.h"

#include <stdexcept>
#include <string>

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
  task_t task{};
  kern_return_t error = task_for_pid(mach_task_self(), pid, &task);
  if (error != KERN_SUCCESS) {
    return 0;
  }

  mach_msg_type_number_t count = TASK_VM_INFO_COUNT;
  task_vm_info_data_t ti{};
  error = task_info(task, TASK_VM_INFO, (task_info_t)&ti, &count);
  if (error != KERN_SUCCESS) {
    return 0;
  }

  return ti.phys_footprint;
#endif
}

size_t currentProcessMemoryUsage() noexcept {
  return processMemoryUsage(currentProcessId());
}

}  // namespace sys
