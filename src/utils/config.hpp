#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <map>

enum ValueType {
  STRING,
  INT,
  FLOAT,
  BOOL
};

struct ConfigValue {
  std::string s;
  int asInt() {
    return std::stoi(s);
  }
  float asFloat() {
    return std::stof(s);
  }
  bool asBool() {
    return s == "true";
  }
};

class Config
{
private:
  inline static std::map<std::string, ConfigValue> values = {
    {"viewport.width", {"800"}},
    {"viewport.height", {"600"}},
    {"viewport.fullscreen", {"false"}},
  };

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