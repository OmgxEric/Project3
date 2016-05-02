#include "Folders.h"

class Explorer
{
private:
	AVL_Tree<Folders> folderTree;
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
		AVLNode<Folders> fldrptr = folderTree.find(fldr);

		//if function returns true, the size of the file list did not change, meaning the file was not added
		if (fldrptr.data.addFileToFolder(fName, fSize))
			std::cout << "File already exists! Please use another name for the file." << std::endl;
		else
			std::cout << "File added successfully." << std::endl;
	}

	void deleteFolder(std::string dPath, std::string dName)
	{
		Folders newFolder(dPath, dName);

		if (folderTree.erase(newFolder))
			std::cout << "Folder deleted successfully." << std::endl;
		else
			std::cout << "Folder does not exist! Please search for another folder name." << std::endl;
	}

	void deleteFile(std::string filePath, std::string fName)
	{
		Folders fldr(filePath);
		AVLNode<Folders> fldrptr = folderTree.find(fldr);

		//if function returns true, the size of the file list did not change, meaning the file was not added
		if (fldrptr.data.removeFileFromFolder(fName))
			std::cout << "File does not exist! Please enter another file name." << std::endl;
		else
			std::cout << "File deleted successfully." << std::endl;
	}
};