#include "xjx.h"
#include "xml_iterator.h"
#include <iostream>

int main() {
  xjx x2x;
  XML_CHECK(x2x.read_xml("../data/test1.xml"));
  XML_CHECK(x2x.write_xml("../data/test1_out.xml"));

  x2x.print_all_nodes();
  return 0;
}
