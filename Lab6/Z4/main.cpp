#include <iostream>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/iterator/advance.hpp>
#include <boost/fusion/include/advance.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/mpl/int.hpp>
#include <map>
using namespace std;
typedef boost::fusion::vector<> MultiVector;
map<string, int> CountTypes (MultiVector vec) {
    map<string, int> Types;
    auto itvStart = begin(vec);
    auto itvStop = end(vec);
    for (auto iter = itvStart; iter != itvStop; advance<boost::mpl::int_<1>>(iter)) {
        string f = typeid(*iter).name();
        cout<<f<<endl;
    }
    return Types;
}
int main () {
    map<string, int> Types;
    MultiVector vec;
    auto vec2 = boost::fusion::push_back(vec, 1);
    Types = CountTypes(vec2);
    cin.ignore();
    cin.get();
    return 0;
}