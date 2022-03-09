#ifndef HONEYBADGER_CONVERTER_HH
#define HONEYBADGER_CONVERTER_HH
#include <cstddef>
#include <vector>

namespace honeybadger::converter
{
/// @brief An interface for classes that will be responsible for converting
/// one type of file into another. By default, these are image/pdf/text files.
class Converter
{
  public:
    /// @brief Main method used to convert between type.
    /// @return Array of byte with converted type.
    virtual std::vector<std::byte> convert() = 0;
    virtual ~Converter() = default;
};
} // namespace honeybadger::converter

#endif