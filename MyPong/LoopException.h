//
// Created by 孙博 on 2017/9/12.
//


#ifndef PONG_LOOPEXCEPTION_H
#define PONG_LOOPEXCEPTION_H
#include <exception>
#include <string>

class WinException:public std::exception{
    std::string s;

public:
    explicit WinException(std::string s):s(s){}

    const char* what() const  noexcept override {
        return s.c_str();
    }
};

class LoseException:public std::exception{
    std::string s;

public:
    explicit LoseException(std::string s):s(s){}

    const char* what() const noexcept override {
        return s.c_str();
    }
};

#endif //PONG_LOOPEXCEPTION_H
