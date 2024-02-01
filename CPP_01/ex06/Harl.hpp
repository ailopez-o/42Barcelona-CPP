#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

enum LogLevel { DEBUG, INFO, WARNING, ERROR, INVALID };

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    void complain(LogLevel level);
};


#endif