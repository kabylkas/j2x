#pragma once

#include <string>
#include <iostream>
#include "tinyxml2.h"
#include "defines.h"
#include "xml_iterator.h"


class xjx {
  private:
    tinyxml2::XMLDocument xml_doc;
    xml_elem* root_xml_node;

  public:
    xjx() = default;
    tinyxml2::XMLError read_xml(const char* file_name);
    tinyxml2::XMLError write_xml(const char* file_name);
    bool operator==(const xjx& other_xjx);

    //debugging methods
    void print_all_nodes();
};
