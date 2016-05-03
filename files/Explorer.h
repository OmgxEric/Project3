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

	void folderSizewrapper(std::string path)
	{
		int filesize = 0;
		Folders sFolder(path);

		AVLNode<Folders> originFolder = folderTree.find(sFolder);
		folderSize(&originFolder, path, filesize);
	}

	int folderSize(AVLNode<Folders>* localroot, std::string fPath, int filesize)
	{
		//add all the file sizes together in the map object
		std::map<std::string, int>::iterator it;

		//if the file at the pointer location contains fPath in its folder pathway, it is a subfolder of the folder
		if (localroot->data.get_folderPath().substr(0, fPath.size() - 1) == fPath)
		{
			for (it = localroot->data.get_filesInFolder().begin(); it != localroot->data.get_filesInFolder().end(); it++)
			{
				it->second += filesize;
			}
		}
		folderSize(localroot->left, fPath, filesize);
		folderSize(localroot->right, fPath, filesize);
		return filesize;
	}

	void folderAndSubfolders(AVL_Tree<Folders>* localroot, std::string fPath)
	{
		
		if (localroot->is_null())
			return;
		//if the file at the pointer location contains fPath in its folder pathway, it is a subfolder of the folder
		//if (localroot->data.get_folderPath().substr(0, fPath.size() - 1) == fPath)
			std::cout << localroot->get_data() << std::endl;
		folderAndSubfolders(&localroot->get_left_subtree(), fPath);
		folderAndSubfolders(&localroot->get_right_subtree(), fPath);
		return;
	}

	AVLNode<Folders> getNode() {}
	AVL_Tree<Folders> get_folderTree() { return folderTree; }
};