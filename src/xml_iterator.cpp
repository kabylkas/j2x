#include "xml_iterator.h"

xml_iterator::xml_iterator(xml_elem* start) {
  this->curr_elem = start;
}

xml_iterator xml_iterator::next() {
  if (!this->curr_elem) {
    return nullptr;
  }

  xml_elem* temp = this->curr_elem;
  if (temp->FirstChildElement()) {
    return xml_iterator(temp->FirstChildElement());
  } else {
    while (temp && !temp->NextSiblingElement()) {
      temp = temp->Parent()->ToElement();
    }
    if (temp) {
      return xml_iterator(temp->NextSiblingElement());
    } else {
      return nullptr;
    }
  }
}

xml_elem* xml_iterator::operator->() const {
  return this->curr_elem;
}

xml_elem* xml_iterator::operator*() const {
  return this->curr_elem;
}

xml_iterator& xml_iterator::operator++() {
  xml_iterator temp = this->next();
  this->curr_elem = *temp;
  return *this;
}

bool xml_iterator::operator!=(const xml_iterator& other_it) {
  return *this != *other_it;
}
