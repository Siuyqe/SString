#ifndef SSTRING_H
#define SSTRING_H
#include <memory>

class SString
{
 /*! Functions,
  *
  */
public:
    SString(const char* str);
    ~SString();

    /*!
    *Out put data
    */
    char* data();

    /*!
    *Append a new string to the tail of string
    */
    void append(const char* str);

    void append(const SString& str);

    /*!
    *Get a data that type of char in a location
    */
   virtual char mid(int locat);
//变量
public:
    
private:
    unsigned int buffLenth;
    std::unique_ptr<char[]>buff;
};


#endif //SSTRING_H