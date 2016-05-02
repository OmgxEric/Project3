

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
	AVL_Tree<Folders> fldrs;

	fileExplorer.addFolder("X");
	fileExplorer.addFolder("Y");
	fileExplorer.addFolder("X", "Z");

	//fldrs.get_left_subtree();
	//fldrs.get_right_subtree();

	return 0;
}