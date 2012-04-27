#ifndef FILE_H
#define FILE_H

#include "FileHandler.h"

class File : private FileHandler
{
protected:
    static unsigned int fetchElementSizeFromFile(const FileDesc &description);
    static void readDataFromFile(const FileDesc &description);
    static void writeDataToFile(const FileDesc &description);
};


#endif // FILE_H
