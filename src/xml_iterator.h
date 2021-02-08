#pragma once
#include "tinyxml2.h"
#include "defines.h"

class xml_iterator {
  private:
    xml_elem* curr_elem;
    
  public:
    xml_iterator() = default;
    xml_iterator(xml_elem* start);
    xml_iterator next();
    xml_iterator& operator++();
    xml_elem* operator->() const;
    xml_elem* operator*() const;
    bool operator!=(const xml_iterator& other_it);
};
