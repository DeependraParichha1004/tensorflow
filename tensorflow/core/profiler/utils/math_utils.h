/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_PROFILER_UTILS_MATH_UTILS_H_
#define TENSORFLOW_CORE_PROFILER_UTILS_MATH_UTILS_H_

namespace tensorflow {
namespace profiler {

// Convert from clock cycles to seconds.
inline double CyclesToSeconds(double cycles, double frequency_hz) {
  // cycles / (cycles/s) = s.
  return cycles / frequency_hz;
}

// Checks the divisor and returns 0 to avoid divide by zero.
inline double SafeDivide(double dividend, double divisor) {
  constexpr double kEpsilon = 1.0E-10;
  if ((-kEpsilon < divisor) && (divisor < kEpsilon)) return 0.0;
  return dividend / divisor;
}

inline double GibiToGiga(double gibi) { return gibi * ((1 << 30) / 1.0e9); }
inline double GigaToGibi(double giga) { return giga / ((1 << 30) / 1.0e9); }

// Calculates GiB/s.
inline double GibibytesPerSecond(double gigabytes, double ns) {
  return GigaToGibi(SafeDivide(gigabytes, ns));
}

}  // namespace profiler
}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_PROFILER_UTILS_MATH_UTILS_H_
