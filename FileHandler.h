/*
 *  FileHandler.h
 *  powaah
 *
 *  Created by Tim Uusitalo on 4/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FILE_HANDLER_H

#define FILE_HANDLER_H

#include <fstream>

struct FileDesc
{
        std::string file_name;
        int size;
        int elements;
        char* data;
};


class FileHandler
{
protected:
        static bool writeBinary(const FileDesc& desc);

        static bool readBinary(const FileDesc& desc);

        static void readPartBinary(std::fstream& f, const FileDesc& desc);

        static void writePartBinary(std::fstream& f, const FileDesc& desc);

        static int getBinaryFileSize(const std::string& file);
};

#endif
