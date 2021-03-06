/*
 * File:   Config.hpp
 * Author: JoPe
 *
 * Created on 28 de abril de 2014, 23:42
 */

#ifndef CONFIG_HPP
#define	CONFIG_HPP

#include <map>
#include <string>
#include "Value.hpp"

namespace cfg
{
  class Config
  {
    std::map<std::string, Value> m_symbolTable;

    Value const& GetProperty(std::string const& i_property, Value::Type const& i_type) const;

    public:
      Config() = default;
      Config(std::string const& i_configFile);
      Config(std::ifstream & i_configFile);
      void LoadConfiguration(std::string const& i_configFile);
      bool const& GetBoolProperty(std::string const& i_boolProperty) const;
      int const& GetIntProperty(std::string const& i_intProperty) const;
      float const& GetFloatProperty(std::string const& i_floatProperty) const;
      std::string const& GetStringProperty(std::string const& i_stringProperty) const;
      bool PropertyExists(std::string const& i_propertyName, Value::Type const& i_valueType) const;
      std::map< std::string, Value >::iterator begin() noexcept;
      std::map< std::string, Value >::iterator end() noexcept;
      std::map< std::string, Value >::const_iterator begin() const noexcept;
      std::map< std::string, Value >::const_iterator end() const noexcept;
      std::map< std::string, Value >::const_iterator cbegin() const noexcept;
      std::map< std::string, Value >::const_iterator cend() const noexcept;
  };
}

#endif	/* CONFIG_HPP */

