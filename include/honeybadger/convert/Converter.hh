#ifndef HONEYBADGER_CONVERTER_HH
#define HONEYBADGER_CONVERTER_HH
#include <cstddef>
#include <vector>

namespace honeybadger::convert
{
/// @brief An interface for classes that will be responsible for converting
/// one type of file into another. By default, these are image/pdf/text files.
class Converter
{
  public:
    virtual std::vector<std::byte> convert() = 0;
    virtual ~Converter() = default;
};
} // namespace honeybadger::convert

#endif