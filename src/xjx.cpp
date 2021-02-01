#include "xjx.h"

tinyxml2::XMLError xjx::read_xml(const char* file_name) {
  return this->xml_doc.LoadFile(file_name);
}

tinyxml2::XMLError xjx::write_xml(const char* file_name) {
  return this->xml_doc.SaveFile(file_name);
}