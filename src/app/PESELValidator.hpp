#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class PESELValidator {
public:
  bool validatePESEL(const std::string &PESEL) const noexcept;

private:
  bool validatePESELSize(const std::string &PESEL) const noexcept;
  bool validatePESELDate(const std::string &PESEL) const noexcept;
  bool validateControlNumber(const std::string &PESEL) const noexcept;
};
