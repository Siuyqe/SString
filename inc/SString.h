#ifndef SSTRING_H
#define SSTRING_H
#include <memory>
/**
 * @file SString.h
 * @author siuyqe \n\n
 * Github : https://github.com/siuyqe \n
 * @brief the SString
 * @copyright The CSerialPort is Copyright (C) 2025 siuyqe <siuyqe@qq.com>. \n
 * You may use, copy, modify, and distribute the SString, under the terms \n
 * of the LICENSE file.
 */
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