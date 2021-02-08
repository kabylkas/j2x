#include "xjx.h"

tinyxml2::XMLError xjx::read_xml(const char* file_name) {
  tinyxml2::XMLError err = this->xml_doc.LoadFile(file_name);
  if (err == tinyxml2::XML_SUCCESS) {
    this->root_xml_node = xml_doc.FirstChildElement();
    this->first = xml_iterator(this->root_xml_node);
    this->last = this->first.next().next();
  }
  return err;
}

tinyxml2::XMLError xjx::write_xml(const char* file_name) {
  return this->xml_doc.SaveFile(file_name);
}

bool xjx::operator==(const xjx& other_xjx) {


  return true;
}

void xjx::print_all_nodes() {
  xml_iterator it = this->first;  
  while (*it) {
    std::cout << it->Name() << "\n"; 
    ++it;
  }
}
