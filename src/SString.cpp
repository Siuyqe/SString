#include "../inc/SString.h"
#include <string.h>

SString::SString(const char* str)
{
    buffLenth = strlen(str)*2;

    buff = std::make_unique<char[]>(buffLenth);
    strcpy_s(buff.get(),buffLenth,str);
    
}

SString::~SString() = default;

char* SString::data()
{
    return buff.get();
}

void SString::append(const char* str)
{
    size_t currentLen = strlen(buff.get());
    size_t appendLen = strlen(str);
    size_t neededLen = currentLen + appendLen + 1; // +1 for null terminator
    
    if (neededLen > buffLenth) {
        size_t newBuffLenth = neededLen>(buffLenth * 2) ? neededLen:buffLenth*2;
        auto newBuff = std::make_unique<char[]>(newBuffLenth);
        
        strcpy_s(newBuff.get(),neededLen,buff.get());
        
        buff = std::move(newBuff);
        buffLenth = newBuffLenth;
    }
    
    strcat_s(buff.get(),neededLen,str);
}

void SString::append(const SString& str)
{
    size_t currentLen = strlen(buff.get());
    size_t appendLen = strlen(str.buff.get());
    size_t neededLen = currentLen + appendLen + 1;

    if (neededLen > buffLenth) {
        size_t newBuffLenth = neededLen>(buffLenth * 2) ? neededLen:buffLenth*2;
        auto newBuff = std::make_unique<char[]>(newBuffLenth);
        
        strcpy_s(newBuff.get(),neededLen, buff.get());
        
        buff = std::move(newBuff);
        buffLenth = newBuffLenth;
    }
    strcat_s(buff.get(),neededLen, str.buff.get());
}

char* SString::mid(int pos)
{
    if(pos > strlen(data()))
        return 0;

    errno_t error;
    error = memmove_s(buff.get(), strlen(buff.get()),buff.get() + pos, strlen(buff.get())-pos+1);
    if(error == ERANGE)
        return 0;

    return buff.get();
}

char* SString::mid(int pos,int len)
{
    if(pos > strlen(data()))
        return 0;

    errno_t error;
    error = memmove_s(buff.get(), strlen(buff.get()),buff.get() + pos, len);
    if((error == ERANGE)||(error == EOVERFLOW))
        return 0;

    memset(buff.get()+len,0,buffLenth-len);
    return buff.get();

}