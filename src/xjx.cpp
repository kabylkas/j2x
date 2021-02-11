#include <iostream>
#include <fstream>
#include <sstream>
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

bool xjx::read_json(const char* file_name) {
  std::ifstream i(file_name);
  try {
    i >> this->json_doc;
  } catch (json::parse_error& e) {
		std::cerr << "message: " << e.what() << '\n'
							<< "exception id: " << e.id << '\n'
							<< "byte position of error: " << e.byte << std::endl;
		return false;
  }

	return true;
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

void xjx::json_to_xml_helper(const json& j, xml_elem* curr_x) {	
  std::stringstream ss;
	for (auto it = j.begin() ; it != j.end(); ++it) {
    ss.str("");
    try {
      ss << it.key();
    } catch (json::exception& e) {
      ss << "item";
    }
		xml_elem* e = this->xml_doc.NewElement(ss.str().c_str());
		if (it->is_structured()) {
      curr_x->InsertEndChild(e);
			json_to_xml_helper(*it, e);
		} else {
      ss.str("");
      ss << it.value();
      e->SetText(ss.str().c_str());
      curr_x->InsertEndChild(e);
		}
	}
}

bool xjx::json_to_xml() {
	this->root_xml_node = this->xml_doc.NewElement("root");
	this->xml_doc.InsertFirstChild(this->root_xml_node);	

	json& j = this->json_doc;
	json_to_xml_helper(j, this->root_xml_node);
  this->write_xml("a.xml");
	return true;
}

void xjx::print_all_nodes() {
  xml_iterator it = this->root_xml_node;  
  while (*it) {
    std::cout << it->Name() << "\n"; 
    ++it;
  }
}
