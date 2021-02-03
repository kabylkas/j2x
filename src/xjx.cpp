#include <stack>
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

bool xjx::operator==(const xjx& other_xjx) {
  return true;
}

void xjx::print_all_nodes() {
  std::stack<tinyxml2::XMLElement*> st;
  st.push(this->root_xml_node);

  while (st.size() > 0) {
    auto& curr = st.top();
    bool pushed = false;
    while (curr) {
      std::cout << curr->Name() << "\n";
      if (curr->GetText()) {
        std::cout << curr->GetText() << "\n";
      }
      if (!curr->NoChildren()) {
        st.push(curr->FirstChildElement());
        curr = curr->NextSiblingElement();
        pushed = true;
        break;
      }
    }

    if (!pushed) {
      st.pop();
    }
  }
}
