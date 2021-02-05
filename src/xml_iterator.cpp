#include "xml_iterator.h"

xml_iterator::xml_iterator(xml_elem* start) {
  this->curr = start;
  this->elem_stack.push(start);
}

xml_elem* xml_iterator:: next() {
  if (this->elem_stack.size() <= 0) {
    return nullptr;
  }

  auto& curr = elem_stack.back();
  if (curr->NoChildren()) {
    uint32_t ptr = elem_stack.size() - 2;
    while (!elem_stack[ptr]->NextSiblingElement() && ptr > 0) {
      --ptr;
    }
    if (ptr < 0) {
      return nullptr;
    } else {
      return elem_stack[ptr]->NextSiblingElement();
    }
  } else {
    return curr->FirstChildElement();
  }
}

void xml_iterator::move_next() {

}

xml_iterator::xml_elem* next(size_t n) {
  auto xml_iter = xml_iterator(this->next());
  while (n > 0) {
    next = 
  }
}

xml_iterator

xml_elem* current() {
  return this->elem_stack.back();
}
