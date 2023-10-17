#pragma once

#define FMT_HEADER_ONLY
#include "format.h"
#include "color.h"

class Print
{
public:
  Print();
  ~Print();

  void print_title(std::string);
  void print_subtitle(std::string);
  void print_info(std::string, auto);
  void print_number(std::string, auto, std::string = "");
};

Print::Print()
{
}

Print::~Print()
{
}

void Print::print_title(std::string label)
{
  fmt::print(fmt::emphasis::underline | fg(fmt::color::cyan), "{}\n\n", label);
}

void Print::print_subtitle(std::string label)
{
  fmt::print(fmt::emphasis::underline | fg(fmt::color::yellow), "\n{}\n\n", label);
}

void Print::print_info(std::string label, auto value)
{
  fmt::print("{} {}\n", fmt::format(fg(fmt::color::yellow_green), "{}:", label), value);
}

void Print::print_number(std::string label, auto value, std::string units)
{
  fmt::print(
      "{} {:.7f} {}\n",
      fmt::format(fg(fmt::color::yellow_green), "{}:", label),
      value,
      fmt::format(fg(fmt::color::blue_violet), "{}", units));
}
