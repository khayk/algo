#pragma once

#include <cstdint>

namespace sys {

/**
 * @brief Returns current process id
 */
uint32_t currentProcessId() noexcept;

/**
 * @brief Get currently occupied memory in bytes for given process id
 *
 * @param pid  Process ID
 *
 * @return Allocated memory in bytes or 0 if error occured
 *
 * @note For Windows the return value is the working set size.
 *       For MacOS the return value is the physical footprint.
 */
size_t processMemoryUsage(uint32_t pid) noexcept;


/**
 * @brief Get currently occupied memory of current process in bytes
 *
 * @return Allocated memory in bytes or 0 if error occured
 */
size_t currentProcessMemoryUsage() noexcept; 

}  // namespace sys
