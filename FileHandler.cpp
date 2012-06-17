/*
 *  FileHandler.h
 *  powaah
 *
 *  Created by Tim Uusitalo on 4/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "FileHandler.h"

bool FileHandler::writeBinary(const FileDesc& desc)
{
	std::fstream file(desc.file_name.c_str(), std::ios::out | std::ios::binary);

	// if file exists
	if (file.is_open())
	{
		file.write(desc.data, desc.size*desc.elements);

		file.close();

		return true;
	}

	return false;
}

bool FileHandler::readBinary(const FileDesc& desc)
{
	std::fstream file(desc.file_name.c_str(), std::ios::in | std::ios::binary);

	if (file.is_open())
	{
		file.read(desc.data, desc.size * desc.elements);

		file.close();

		return true;
	}

	return false;
}

void FileHandler::readPartBinary(std::fstream& f, const FileDesc& desc)
{
	f.read(desc.data, desc.size*desc.elements);
}

void FileHandler::writePartBinary(std::fstream& f, const FileDesc& desc)
{
	f.write(desc.data, desc.size*desc.elements);
}

int FileHandler::getBinaryFileSize(const std::string& file)
{
	std::fstream f(file.c_str(), std::ios::in | std::ios::binary);

	if (f.is_open())
	{
		f.seekg(0, std::ios::end);

		int size = (int)f.tellg();

		f.seekg(0, std::ios::beg);

		f.close();

		return size;

	}

	return 0;
}
