

#include "Explorer.h"
#include <list>
using namespace std;

//void add_folder(string path, string folder_name) {}
//void delete_folder(string path, string folder_name) {}
//void add_file(string path, string file_name, int size) {}
//File get_file(string path, string file_name) {}
//list<File> get_files(string path, string file_name){}
//void delete_file(string path, string file_name){}


int main(){

	//AVL_Tree<string> AVL;

	//bool result = AVL.is_null();

	//Employee* empl=new Employee("X");
	//Employee* emp2=new Employee("Y");

	//AVL_Tree<Employee*> AVL_Employees;

	//AVL_Employees.insert(empl);

	//AVL_Employees.insert(emp2);

	//Employee* emp = AVL_Employees.find(empl);

	//emp->set_name("Z");

	////AVL.insert(50);
	////AVL.insert(60);
	////AVL.insert(70);


	//AVL.insert("The");
	//AVL.insert("quick");

	//

	//AVL.insert("brown");
	//AVL.insert("fox");
	//AVL.insert("jumps");
	//AVL.insert("over");
	//AVL.insert("the");
	//AVL.insert("lazy");
	//AVL.insert("dog");

	//AVL.erase("jumps");

	//AVL_Tree<string> right_subtree = AVL.get_right_subtree();

	//AVL_Tree<string> left_subtree = AVL.get_left_subtree();

	Explorer fileExplorer;

	int selection = 0;
	while (selection > 6 || selection < 1)
	{
		std::cout << "Please select an option from the list below:\n"
			<< "1 - Add Folder\n"
			<< "2 - Delete Folder\n"
			<< "3 - Add File\n"
			<< "4 - Retrieve One File\n"
			<< "5 - Retrieve Multiple Files\n"
			<< "6 - Add Folder" << std::endl;
		std::cin >> selection;

		if (selection > 6 || selection < 1)
		{
			std::cout << "Invalid selection. Please enter a value from the list above: ";
			std::cin >> selection;
		}
		system("CLS");
	}
	fileExplorer.addFolder("X");
	fileExplorer.addFolder("Y");
	fileExplorer.addFolder("X", "Z");

	Folders rootFldr("X");
	AVLNode<Folders> fPtr = fileExplorer.get_folderTree().get_data();
	//currently not working. The above code creates a new AVLNode based on the data from the find() function. We need to find the actual AVLNode
	fileExplorer.folderAndSubfolders(&fileExplorer.get_folderTree(), "X");

	system("PAUSE");
	return 0;
}