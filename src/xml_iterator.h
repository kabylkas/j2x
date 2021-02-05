#pragma once
#include <deque>
#include "tinyxml2.h"

using tinyxml2::XMLElement = xml_elem;

class xml_iterator {
  private:
    std::deque<xml_elem*> elem_stack;
    
  public:
    xml_iterator() = default;
    xml_iterator(xml_elem* start);
    xml_elem* next();
    xml_elem* next(size_t n);
    xml_elem* current();
    xml_elem* begin();
    xml_elem* end();
};
