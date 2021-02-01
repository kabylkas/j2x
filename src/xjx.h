#pragma once

#include <string>
#include <iostream>
#include "tinyxml2.h"

#define XML_CHECK(xml_func_result)\
  if (xml_func_result != tinyxml2::XML_SUCCESS) {\
    throw std::runtime_error("XML function was not successful");\
  }

class xjx {
  private:
    tinyxml2::XMLDocument xml_doc;

  public:
    xjx() = default;
    tinyxml2::XMLError read_xml(const char* file_name);
    tinyxml2::XMLError write_xml(const char* file_name);
};