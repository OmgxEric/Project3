#include "Folders.h"

class Explorer
{
private:
	AVL_Tree<Folders> folderTree;

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

		//if function returns true, the size of the file list did not change, meaning the file was not added
		if (folderTree.find(fldr).addFileToFolder(fName, fSize))
			std::cout << "File already exists! Please use another name for the file." << std::endl;
		else
			std::cout << "File added successfully." << std::endl;
	}

	void deleteFolder(std::string dPath, std::string dName)
	{
		Folders delFolder(dPath, dName);

		if (folderTree.erase(delFolder))
			std::cout << "Folder deleted successfully." << std::endl;
		else
			std::cout << "Folder does not exist! Please search for another folder name." << std::endl;
	}

	void deleteFile(std::string filePath, std::string fName)
	{
		Folders fldr(filePath);

		//if function returns true, the size of the file list did not change, meaning the file was not added
		if (folderTree.find(fldr).removeFileFromFolder(fName))
			std::cout << "File does not exist! Please enter another file name." << std::endl;
		else
			std::cout << "File deleted successfully." << std::endl;
	}

	void folderSizewrapper(std::string path)
	{
		int filesize = 0;
		folderSize(&folderTree, path, filesize);
	}

	int folderSize(AVL_Tree<Folders>* localroot, std::string fPath, int filesize)
	{
		if (localroot->is_null())
			return 0;
		
		//add all the file sizes together in the map object
		std::map<std::string, int>::iterator it;
		Folders tempFldr = localroot->get_data();

		//if the file at the pointer location contains fPath in its folder pathway, it is a subfolder of the folder
		if (tempFldr.get_folderPath().substr(0, fPath.size()) == fPath)
		{
			for (it = tempFldr.get_filesInFolder().begin(); it != tempFldr.get_filesInFolder().end(); it++)
			{
				it->second += filesize;
			}
		}
		folderSize(&localroot->get_left_subtree(), fPath, filesize);
		folderSize(&localroot->get_right_subtree(), fPath, filesize);
		return filesize;
	}

	void folderAndSubfolders(AVL_Tree<Folders>* localroot, std::string fPath)
	{
		if (localroot->is_null())
			return;
		Folders tempFldr = localroot->get_data();
		
		//if the file at the pointer location contains fPath in its folder pathway, it is a subfolder of the folder
		if (tempFldr.get_folderPath().substr(0, fPath.size()) == fPath)
			std::cout << tempFldr << std::endl;
		folderAndSubfolders(&localroot->get_left_subtree(), fPath);
		folderAndSubfolders(&localroot->get_right_subtree(), fPath);
		return;
	}

	AVLNode<Folders> getNode() {}
	AVL_Tree<Folders> get_folderTree() { return folderTree; }
};