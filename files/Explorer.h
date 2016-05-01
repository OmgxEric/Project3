#include "Folders.h"

class Explorer
{
private:
	AVL_Tree<Folders> folderTree;
	Folders folder;
	AVL_Tree<Folders>* folderptr;

public:

	void addFolder(std::string sName)
	{
		Folders newFolder(sName);

		if (folderTree.insert(newFolder))
			std::cout << "Folder added successfully." << std::endl;
		else
			std::cout << "Folder already exists! Please use another name for the folder." << std::endl;
	}

	void addFolder(std::string sPath, std::string sName)
	{
		Folders newFolder(sPath, sName);

		if (folderTree.insert(newFolder))
			std::cout << "Folder added successfully." << std::endl;
		else
			std::cout << "Folder already exists! Please use another name for the folder." << std::endl;
	}

	void addFile(std::string filePath, std::string fName, int fSize)
	{
		Folders fldr(filePath);
		Folders* fldrptr = &folderTree.find(fldr);

		//if function returns true, the size of the file list did not change, meaning the file was not added
		if (fldrptr->addFileToFolder(fName, fSize))
			std::cout << "File already exists! Please use another name for the file." << std::endl;
		else
			std::cout << "File added successfully." << std::endl;
	}
};