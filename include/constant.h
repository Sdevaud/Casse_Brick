#pragma once

namespace cons {
  template<typename T>
  constexpr T ZERO = T{0};

  template<typename T>
  constexpr T tol = T{1e-6};
}

