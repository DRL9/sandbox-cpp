#pragma once

#include <stdexcept>
#include <string>

class greater_error : public std::range_error {
 public:
  explicit greater_error(const std::string& w) : std::range_error(w) {};
};