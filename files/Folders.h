#include "File2.h";
#include <map>

class Folders
{
private:
	std::string folderName;
	std::map <std::string, int> filesInFolder;

public:
	Folders(std::string name)
	{
		folderName = name;
		filesInFolder;
	}

	void addFile(std::string fName, int fSize){// add file name and size}

	void addSubfolder (std::string sName){}

	int folderSize()
	{
		//add all the file sizes together in the map object
	}
};