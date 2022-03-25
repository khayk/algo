#include "Problems.h"

namespace alg {

int minimumLengthSubstring(const std::string_view s, const std::string_view t) {
  // Quick termination, as it is impossible to find such a substring
  const auto sizeT = static_cast<int>(t.length());
  const auto sizeS = static_cast<int>(s.length());

  if (sizeS < sizeT) {
    return -1;
  }

  std::array<int, 256> freqT{};
  std::array<int, 256> freqS{};
  int start = 0;
  int count = 0;
  int minLength = sizeS + 1;

  for (const unsigned char ch : t) {
    ++freqT[ch];
  }

  for (int i = 0; i < sizeS; ++i) {
    unsigned char ch = s[i];
    ++freqS[ch];

    if (freqS[ch] <= freqT[ch]) {
      ++count;
    }

    if (count == sizeT) {
      // Minimize window
      unsigned char x = s[start];

      while (freqS[x] > freqT[x] || freqT[x] == 0) {
        if (freqS[x] > freqT[x]) {
          --freqS[x];
        }
        ++start;
        x = s[start];
      }

      // Update window size
      auto winLength = i - start + 1;
      if (minLength > winLength) {
        minLength = winLength;
      }
    }
  }

  if (minLength == sizeS + 1) {
    return -1;
  }

  return minLength;
}

}  // namespace alg