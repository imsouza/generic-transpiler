#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace boost::spirit;

template <typename T>
bool parse_numbers(T b, T e)
{
    using qi::double_;
    using qi::phrase_parse;
    using ascii::space;

    auto r { phrase_parse(
        b, e,
        double_ >> *(',' >>  double_),
        space
    ) };
    if (b != e)
        return false;
    return r;
}

int main()
{
    string s;
    int v;
    getline(cin, s);
    auto match { qi::phrase_parse(begin(s), end(s), ascii::digit, ascii::space) };
    qi::parse(begin(s), end(s), int_, v);
    cout << boolalpha << match << '\n';
    cout << "Val " << v << '\n';
    cout << boolalpha << parse_numbers(begin(s), end(s)) << '\n';

    return 0;
}


