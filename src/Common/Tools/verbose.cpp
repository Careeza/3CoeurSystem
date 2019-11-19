#include "tools.h"

void    CS_Tools::verbose(t_debug debugSource, std::string element, ...)
{
	unsigned long	i;
	va_list			op;

	i = 0;
	va_start(op, element);
    if (debug != LEVEL0)
    {
        if (debugSource <= debug)
        {
            while (i < element.size())
            {
                if (element[i] == 's')
                    std::cout << va_arg(op, char*);
                else if (element[i] == 'd')
                    std::cout << va_arg(op, int);
                else if (element[i] == 'f')
                    std::cout << va_arg(op, double);
                i++;
                if (i != element.size())
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
	va_end(op);
}
