#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <map>

struct ConfigValue
{
  std::string s;
  std::string asString()
  {
    return s;
  }
  int asInt()
  {
    return std::stoi(s);
  }
  float asFloat()
  {
    return std::stof(s);
  }
  bool asBool()
  {
    return s == "true";
  }
};

class Config
{
private:
  inline static std::map<std::string, ConfigValue> values = {
      {"viewport.width", {"800"}},
      {"viewport.height", {"600"}},
      {"viewport.title", {"Hypergon"}},
      {"viewport.clearColor", {"#e5e5e5ff"}},
      {"viewport.nearPlane", {"0.1"}},
      {"viewport.farPlane", {"1000.0"}}};

public:
  /**
   * Get a config value.
   */
  static ConfigValue get(std::string key)
  {
    return values[key];
  }

  /**
   * Set a config value.
   */
  static void set(std::string key, ConfigValue value)
  {
    values[key] = value;
  }
};

#endif // CONFIG_HPP