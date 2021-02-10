#include "xjx.h"

tinyxml2::XMLError xjx::read_xml(const char* file_name) {
  tinyxml2::XMLError err = this->xml_doc.LoadFile(file_name);
  if (err == tinyxml2::XML_SUCCESS) {
    this->root_xml_node = xml_doc.FirstChildElement();
  }
  return err;
}

tinyxml2::XMLError xjx::write_xml(const char* file_name) {
  return this->xml_doc.SaveFile(file_name);
}

xml_elem* xjx::get_root_xml_node() const {
  return this->root_xml_node;
}

bool xjx::operator==(const xjx& other_xjx) {
  xml_iterator it1 = xml_iterator(this->root_xml_node);
  xml_iterator it2 = xml_iterator(other_xjx.get_root_xml_node());

  while (*it1 && *it2) {
    std::string s1(it1->Name());
    if (s1.compare(it2->Name()) != 0) {
      return false;
    }
    ++it1;
    ++it2;
  }

  return true;
}

bool xjx::operator!=(const xjx& other_xjx) {
  return !this->operator==(other_xjx);
}

void xjx::print_all_nodes() {
  xml_iterator it = this->root_xml_node;  
  while (*it) {
    std::cout << it->Name() << "\n"; 
    ++it;
  }
}
