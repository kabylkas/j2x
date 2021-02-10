#include "xjx.h"
#include "json.hpp"
#include "xml_iterator.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
  xjx x2x;
  XML_CHECK(x2x.read_xml("../data/test1.xml"));
  XML_CHECK(x2x.write_xml("../data/test1_out.xml"));
  x2x.print_all_nodes();

  xjx x2x_2;
  XML_CHECK(x2x_2.read_xml("../data/test1_out.xml"))
  if (x2x_2 == x2x) {
    std::cerr << "XMLs are equal\n";
  } else {
    std::cerr << "XMLs are NOT equal\n";
  }

  json j;
  std::ifstream i("../data/test1.json");
  i >> j;

  std::ofstream o("../data/test1_out.json");
  o << std::setw(4) << j << "\n";
  return 0;
}
