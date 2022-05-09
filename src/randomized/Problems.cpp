#include "Problems.h"
#include <limits>
#include <array>

namespace alg {

std::pair<size_t, size_t> minWindow(std::string_view source,
                                    std::string_view pattern) {
  constexpr auto invalidIndex = static_cast<size_t>(-1);
  constexpr size_t charsCount = 256;

  if (source.size() < pattern.size()) {
    return {invalidIndex, 0};
  }

  std::array<size_t, charsCount> hashPat = {};
  std::array<size_t, charsCount> hashSrc = {};
  auto startIndex = invalidIndex;
  size_t start = 0;
  size_t count = 0;
  size_t minLength = std::numeric_limits<size_t>::max();
 
  for (const unsigned char ch : pattern) {
    ++hashPat[ch];
  }
  
  for (size_t j = 0; j < source.size(); ++j) {
    const unsigned char ch = source[j];
    ++hashSrc[ch];

    if (hashSrc[ch] <= hashPat[ch]) {
      ++count;
    }

    if (count == pattern.size()) {
      // Trying to minimize the window
      unsigned char x = source[start];

      while (hashSrc[x] > hashPat[x] || hashPat[x] == 0) {
        if (hashSrc[x] > hashPat[x]) {
          --hashSrc[x];
        }
        ++start;
        x = source[start];
      }

      // Update window size
      auto windowsLen = j - start + 1;
      if (minLength > windowsLen) {
        minLength = windowsLen;
        startIndex = start;
      }
    }
  }
  
  return {startIndex, minLength};
}


}  // namespace alg
