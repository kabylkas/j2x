#pragma once
#include "tinyxml2.h"

using xml_elem = tinyxml2::XMLElement;

#define XML_CHECK(xml_func_result)\
  if (xml_func_result != tinyxml2::XML_SUCCESS) {\
    throw std::runtime_error("XML function was not successful");\
  }
