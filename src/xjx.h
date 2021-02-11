#pragma once

#include "tinyxml2.h"
#include "defines.h"
#include "xml_iterator.h"


class xjx {
  private:
    //xml
    xml_document xml_doc;
    xml_elem* root_xml_node;

    //json
    json json_doc;

  public:
    xjx() = default;
    tinyxml2::XMLError read_xml(const char* file_name);
    tinyxml2::XMLError write_xml(const char* file_name);
    bool read_json(const char* file_name); 
    //bool write_json(const char* file_name); 
    xml_elem* get_root_xml_node() const;
    bool operator==(const xjx& other_xjx);
    bool operator!=(const xjx& other_xjx);
		
		//conversions
		void json_to_xml_helper(const json& j, xml_elem* curr_x);
		bool json_to_xml();
    //debugging methods
    void print_all_nodes();
};
