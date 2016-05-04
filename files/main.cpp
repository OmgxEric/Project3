
#include <iostream>
#include "Explorer.h"

using namespace std;

int main(){
	Explorer fileExplorer;
	string folderName, fileName, folderPath, pFolder;
	int fileSize, selection = 0;
	bool repeat = 0;
	File sFile;
	list<File> files;
	list<File>::iterator filesItr;

	cout << "Please select an option from the list below:\n"
		<< "1 - Add Folder\n"
		<< "2 - Delete Folder\n"
		<< "3 - Add File\n"
		<< "4 - Retrieve One File\n"
		<< "5 - Retrieve Multiple Files\n"
		<< "6 - Delete File\n"
		<< "7 - Exit" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		cout << "\nPlease enter the name of the folder to be added: ";
		getline(cin, folderName);

		cout << "Does this folder have a parent folder? (Y or N) ";
		cin >> pFolder;
		do
		{
			if (pFolder == "Y" || pFolder == "y" || pFolder == "yes" || pFolder == "Yes" || pFolder == "YES")
			{
				cout << "Please enter the folder pathway, excluding the folder name (Format: Folder/subfolder): ";
				getline(cin, folderPath);

				fileExplorer.addFolder(folderPath, folderName);
				repeat = 0;
			}
			else if (pFolder == "N" || pFolder == "n" || pFolder == "no" || pFolder == "No" || pFolder == "NO")
			{
				fileExplorer.addFolder(folderName);
				repeat = 0;
			}
			else
			{
				cout << "Invalid entry. Please enter Y or N: ";
				cin >> pFolder;
				repeat = 1;
			}
		} while (repeat = 1);
		break;
	case 2:
		cout << "\nPlease enter the name of the folder to be deleted: ";
		getline(cin, folderName);

		cout << "Does this folder have a parent folder? (Y or N) ";
		cin >> pFolder;
		do
		{
			if (pFolder == "Y" || pFolder == "y" || pFolder == "yes" || pFolder == "Yes" || pFolder == "YES")
			{
				cout << "Please enter the folder pathway, excluding the folder name (Format: Folder/subfolder): ";
				getline(cin, folderPath);
				fileExplorer.deleteFolder(folderPath, folderName);
				repeat = 0;
			}
			else if (pFolder == "N" || pFolder == "n" || pFolder == "no" || pFolder == "No" || pFolder == "NO")
			{
				fileExplorer.deleteFolder(folderName);
				repeat = 0;
			}
			else
			{
				cout << "Invalid entry. Please enter Y or N: ";
				cin >> pFolder;
				repeat = 1;
			}
		} while (repeat = 1);
		break;
	case 3:
		cout << "\nPlease enter the name of the file to be added: ";
		getline(cin, fileName);

		cout << "Please enter the file's size (integer value, no units): ";
		cin >> fileSize;

		cout << "Please enter the folder pathway, including the name of the folder containing the file (Format: Folder/subfolder): ";
		getline(cin, folderPath);
		
		fileExplorer.addFile(folderPath, fileName, fileSize);
		break;
	case 4:
		cout << "\nPlease enter the name of the file to be displayed: ";
		getline(cin, fileName);

		cout << "Please enter the folder pathway, including the name of the folder containing the file (Format: Folder/subfolder): ";
		getline(cin, folderPath);

		//retrieves single file
		sFile = fileExplorer.getFile(folderPath, fileName);

		if (sFile.get_fileName().empty())
			cout << "File not found!" << endl;
		else
			cout << "File Name: " << sFile.get_fileName()
				<< "\t|\tFile Size: " << sFile.get_fileSize();
		break;
	case 5:
		cout << "\nPlease enter search term for the file query: ";
		getline(cin, fileName);

		files = fileExplorer.getFiles(&fileExplorer.get_folderTree(), fileName);
		if (files.empty())
			cout << "No matches found that match your query." << endl;
		else
		{
			cout << "Files containing search term:";
			for (filesItr == files.begin(); filesItr != files.end(); filesItr++)
				cout << "\nFile Name: " << filesItr->get_fileName()
				<< "\t|\tFile Size: " << filesItr->get_fileSize();
		}
		break;
	case 6:
		cout << "\nPlease enter the name of the file to be deleted: ";
		getline(cin, fileName);

		cout << "Please enter the folder pathway, including the name of the folder containing the file (Format: Folder/subfolder): ";
		getline(cin, folderPath);

		fileExplorer.deleteFile(folderPath, fileName);
		break;
	case 7:
		exit;
		break;
	default:
		while (selection > 7 || selection < 1)
		{
			cout << "Invalid selection. Please enter a value from the list above: ";
			cin >> selection;
		}
		break;
	}

	system("PAUSE");
	return 0;
}