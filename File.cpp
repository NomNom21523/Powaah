#include "File.h"

#include <iostream>

unsigned int File::fetchElementSizeFromFile(const FileDesc &description)
{
    std::fstream dataStream(description.file_name.c_str(), std::ios::in | std::ios::binary);
    FileDesc header;

    if (dataStream.is_open()) {
        if (FileHandler::getBinaryFileSize(description.file_name) == 0) {
            return 0;
        }

        unsigned int elements = 0;
        header.elements = 1;
        header.data = (char*)&elements;
        header.size = sizeof(unsigned int);
        FileHandler::readPartBinary(dataStream, header);
        dataStream.close();
        std::cout << "Elements: " << elements << std::endl;
        return elements;
    }
    return 0;
}

void File::readDataFromFile(const FileDesc &description)
{
    std::fstream dataStream(description.file_name.c_str(), std::ios::in | std::ios::binary);

    if (dataStream.is_open()) {
        FileDesc header;
        unsigned int elements = 0;
        header.elements = 1;
        header.data = (char*)&elements;
        header.size = sizeof(unsigned int);
        // read header
        FileHandler::readPartBinary(dataStream, header);

        if (elements > 0) {
            std::cout << "Elements: " << elements << std::endl;
            std::cout << "Pointer: " << description.data << " elements: " << description.elements << " size: " << description.size << " filename: " << description.file_name << std::endl;
            // read rest of the file
            FileHandler::readPartBinary(dataStream, description);
        }
    }
}

void File::writeDataToFile(const FileDesc &description)
{
    std::fstream fileStream;
    FileDesc header;

    fileStream.open(description.file_name.c_str(), std::ios::out | std::ios::binary);

	// insert header first, which is a number of elements
	// insert before everything else
	unsigned int elements = description.elements;

	header.size = sizeof(unsigned int);
	header.data = (char*)&elements;
	header.elements = 1;
	// write header
	FileHandler::writePartBinary(fileStream, header);

	// write the data
	FileHandler::writePartBinary(fileStream, description);

	fileStream.close();
}
