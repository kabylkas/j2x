#pragma once
#include <sstream>
#include <stdexcept>
#include "tinyxml2.h"
#include "json.hpp"

using xml_elem = tinyxml2::XMLElement;
using xml_document = tinyxml2::XMLDocument;
using xml_node = tinyxml2::XMLNode;

using json = nlohmann::json;

static void should_be_true(bool b, int line) {
  if (!b) {
    std::stringstream ss;
    ss << "should_be_true() on line " << line << " failed!\n";
    throw std::runtime_error(ss.str());
  }
}

#define I(a) try {\
    should_be_true(a, __LINE__);\
  } catch (std::exception& e) {\
    std::cerr << e.what() << std::endl;\
    exit(1);\
  }
