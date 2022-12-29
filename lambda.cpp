#include<locale>
#include<string.h>
#include<algorithm>
#include <cstdio>
constexpr size_t _maxlen = 128;
using namespace std;
/* class ftitle{

    char lastc;
    public:
        ftitle():lastc(0){}
        char operator () (const char& c) {
            const char r = (lastc == ' ' || lastc == 0) ? toupper(c): tolower(c); 
            lastc = c;
            return r;
        }

}; */

int main(){

    char s[] = "big light in sky slated to appear in east";
 //   transform(s, s+strnlen(s, _maxlen), s, ftitle());
    char lastc = 0;
    transform(s, s + strnlen(s, _maxlen), s, [&lastc] (const char& c ) -> char {
            const char r = (lastc == ' ' || lastc == 0) ? toupper(c): tolower(c); 
            lastc = c;
            return r;
        }
    );
    puts(s);
}