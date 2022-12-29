#include <string.h>
class String{

    char* str;
    public:
        String(): str(nullptr) {
            str = new char[1];
            str[0] = '\0';
        } 

        String(char* val) {
            if(val == nullptr){
                str = new char[1];
                str[0] = '\0';
            }
            else{
                str = new char[strlen(val)+1];
                strcpy(str, val);
            }
        } 

        String(const String& str1){
            
            //this->str = new char[strlen(str1)+1];

        }

};