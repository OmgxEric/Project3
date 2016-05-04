#include "File.h"
#include "AVL_Tree.h"
#include <iostream>
#include <map>

class Folders
{
private:
	std::string folderName
		, folderPath;
	AVL_Tree<Folders> folderTree;
	std::map <std::string, File> filesInFolder;

public:
	Folders() 
	{
		folderName = "/";
	}

	//creates folder name and map of file list for root folder
	Folders(std::string name)
	{
		folderName = name;
		folderPath = name;
		filesInFolder;
	}
	//creates folder name and map of file list for subfolders
	Folders(std::string path, std::string name)
	{
		folderName = name;
		folderPath = path + "/" + folderName;
		filesInFolder;
	}

	//inserts file name and size into map object with the file name as the ID
	bool addFileToFolder(std::string fName, int fSize)
	{
		int originalSize = filesInFolder.size();
		File newFile(fName, fSize);

		filesInFolder[fName] = (fName, newFile);

		return originalSize == filesInFolder.size();
	}

	bool removeFileFromFolder(std::string fName)
	{
		int originalSize = filesInFolder.size();

		filesInFolder.erase(fName);

		return originalSize == filesInFolder.size();
	}

	//first compares the size of the string, allowing for shorter strings to be higher in the heirarchy
	//then compares the strings themselves
	friend bool operator<(const Folders& f1, const Folders& f2)
	{
		if (f1.folderPath.size() < f2.folderPath.size())
			return true;
		else
			return f1.folderPath < f2.folderPath;
	}

	friend std::ostream& operator<<(std::ostream& os, const Folders& folder)
	{
		os << folder.folderPath << std::endl;
		return os;
	}

	const std::string get_folderName() { return folderName; }
	const std::string get_folderPath() { return folderPath; }
	
	std::map < std::string, File > get_filesInFolder() { return filesInFolder; }
};

