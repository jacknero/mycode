/*
 * =====================================================================================
 *
 *       Filename:  test.cxx
 *
 *    Description:  CURSOR>BOOST_TETS
 *
 *        Version:  1.0
 *        Created:  2009Ç¯08·î26Æü 16»þ41Ê¬47ÉÃ
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH S«ädwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <boost/program_options.hpp>
using namespace std;
using namespace boost::program_options;

int main(int argc, char* argv[])
{
  // ¿¿¿¿¿¿¿¿
  options_description opt("入力");
  opt.add_options()
    ("help,h",                                  "¿¿¿¿¿¿")
    ("op"   , value<string>(),                  "¿¿¿¿¿(add,sub,mul,div)")
    ("lhs,L", value<int>()->default_value(100), "¿")
    ("rhs,R", value<int>()->default_value(200), "¿");

  // argc, argv ¿¿¿¿¿¿¿¿¿vm¿¿¿
  variables_map vm;
  store(parse_command_line(argc, argv, opt), vm);
  notify(vm);

  if( vm.count("help") || !vm.count("op") )
    cout << opt << endl; // ¿¿¿¿¿
  else
  {
    string op = vm["op"].as<string>();
    int   lhs = vm["lhs"].as<int>();
    int   rhs = vm["rhs"].as<int>();
    if( op=="add" ) cout << lhs+rhs << endl;
    if( op=="sub" ) cout << lhs-rhs << endl;
    if( op=="mul" ) cout << lhs*rhs << endl;
    if( op=="div" ) cout << lhs/rhs << endl;
  }
}
