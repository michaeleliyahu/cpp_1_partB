#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
int main() {

	cout << ariel::snowman(11114411) << endl;   
     /* hat+build had+buils body+base:
_===_+(.,.)+( : )+( : )
total:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(33232124) << endl;   
    /*  hat+build had+build body+base:
   _
  /_\+\(o_O)+ (] [)>+ (   )
total:
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	try {
		cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}
}