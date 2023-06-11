#include <iostream>
#include "string.h"
class StringK
{
    public:
    char* m_str;
    int m_size;

public:
    StringK(const char* buffer)
    {
        int size = strlen(buffer);
        m_size = size+1;
        m_str = new char[m_size];
        strcpy(m_str, buffer);
    }
    StringK(const StringK& crObj)
    {
        m_size = crObj.m_size;
        m_str = new char[m_size];
        strcpy(m_str, crObj.m_str);
    }   
    const StringK& operator=(const StringK& crObj)
    {
        //if(!crObj)
        //    return *this;
        this->m_size = crObj.m_size;
        this->m_str = new char[m_size];
        strcpy(m_str, crObj.m_str);
        return *this;
    }   

    StringK operator+(const StringK& crObj)
    {
        StringK str;
        str.m_size = this->m_size + crObj.m_size;
        str.m_str = new char[str.m_size + 1];
        strcpy(str.m_str, this->m_str);
        strcpy(str.m_str+6, crObj.m_str);
        return str;
    }   

    StringK() : m_str{nullptr}
    {
        m_size = 1;
        m_str = new char[m_size];
        m_str[0] = '\0';
    } 
    ~StringK()
    {
        m_str = nullptr;
        delete[] m_str;
        m_size=0;
    }
    //StringK operator<<()
    //operator*
};

int main()
{
    StringK obj("Kumar Sethi");
    std::cout<<obj.m_str<<std::endl;

    StringK obj2(obj);
    std::cout<<obj2.m_str<<std::endl;

    StringK obj3 = obj;
    std::cout<<obj3.m_str<<std::endl;

    StringK obj4;
    obj4 = obj;
    std::cout<<obj4.m_str<<std::endl;

    StringK str("Ksethi");
    StringK str2("1234");
    StringK str3 = str + str2;
    str = str + str3; 
    std::cout<<str3.m_str<<std::endl;

}