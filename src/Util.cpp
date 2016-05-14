/**
 * \brief Contains utility functions
 */

#include "Util.h"

namespace util
{
    /**
     * \brief Retrieves an envrionment variable 
     * @param var
     * @return Envrionment variable
     */
    std::string getEnvironmentVariable(const std::string& variable) 
    {
        const char * envrionmentVariable = ::std::getenv(variable.c_str());
        if (envrionmentVariable == 0) 
        {
            return "environment variable not found\n";
        }
        else 
        {
            return envrionmentVariable;
        }
}
}