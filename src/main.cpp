#include "xjx.h"
#include "xml_iterator.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
  xjx x2x;
  XML_CHECK(x2x.read_xml("../data/test1.xml"));
  XML_CHECK(x2x.write_xml("../data/test1_out.xml"));
  //x2x.print_all_nodes();

  xjx x2x_2;
  XML_CHECK(x2x_2.read_xml("../data/test1_out.xml"))
  if (x2x_2 == x2x) {
    std::cerr << "XMLs are equal\n";
  } else {
    std::cerr << "XMLs are NOT equal\n";
  }

	xjx x1;
	x1.read_json("../data/generated.json");
	x1.json_to_xml();
  return 0;
}
