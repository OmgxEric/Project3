#include "File2.h"
#include "AVL_Tree.h"
#include <iostream>
#include <map>

class Folders
{
private:
	std::string folderName
		, folderPath;
	AVL_Tree<Folders> folderTree;
	std::map <std::string, int> filesInFolder;

public:
	//creates folder name and map of file list for root folder
	Folders(std::string name)
	{
		folderName = name;
		filesInFolder;
	}
	//creates folder name and map of file list for subfolders
	Folders(std::string path, std::string name)
	{
		folderName = name;
		folderPath = path + "/" + folderName;
		filesInFolder;
	}

	//identifies where to insert file according to file path, inserts file name and size into map object with the
	//file name as the ID
	//CONSIDER REVISING
	void addFile(std::string filePath, std::string fName, int fSize)
	{
		std::pair <std::string, bool> fileInsert = std::map<std::string, int>::value_type(fName, fSize);
	}

	//for the root folder, which will not need a file path
	void addFolder(std::string sName)
	{
		Folders newFolder(sName);

		if (!folderTree.insert(newFolder))
			std::cout << "Folder already exists!" << std::endl;
		else
			std::cout << "Folder created." << std::endl;
	}

	//for all subfolders of the root folder
	void addFolder(std::string sPath, std::string sName)
	{
		Folders newFolder(sPath, sName);

		if (!folderTree.insert(newFolder))
			std::cout << "Folder already exists!" << std::endl;
		else
			std::cout << "Folder created." << std::endl;
	}

	void folderSizewrapper() 
	{
		int filesize = 0;
		folderSize(folderTree, filesize);
	}

	void folderSize(AVL_Tree localroot, int filesize)
	{
		//add all the file sizes together in the map object
		std::map<std::string, int>::iterator it;
		for (it = filesInFolder.begin(); it != filesInFolder.end(); it++)
		{
			it->second += filesize;
		}
		folderSize(localroot->left, filesize);
		folderSize(localroot->right, filesize);
	}

	bool operator <(Folders& folder1)
	{
		if (folderPath < folder1.get_folderPath())
			return true;
	}

	bool operator =(Folders& folder1)
	{
		if (folderPath == folder1.get_folderPath())
			return true;
	}

	std::string get_folderName() { return folderName; }
	std::string get_folderPath() { return folderPath; }
	std::map < std::string, int > get_filesInFolder() { return filesInFolder; }
};