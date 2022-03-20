#ifndef HONEYBADGER_CONVERTER_HH
#define HONEYBADGER_CONVERTER_HH
#include <cstddef>
#include <vector>

namespace honeybadger::converter
{
enum class Format
{
    Undefined = 0,
    PDF,
    PNG
};

/// @brief An interface for classes that will be responsible for converting
/// one type of file into another. By default, these are image/pdf/text files.
class Converter
{
  public:
    /// @brief Main method used to convert between type.
    /// @param convertTo What you want to convert the PDF to.
    /// @return Array of byte with converted type.
    virtual std::vector<std::byte> convert(const Format convertTo) = 0;
    virtual ~Converter() = default;
};
} // namespace honeybadger::converter

#endif