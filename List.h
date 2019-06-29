#ifndef List_h
#define List_h
#include<string>
#include<fstream>
using namespace std;

struct Node{ //struct inside the list
    int ID; 
    string Name;
    string Category;
    int Price;
    int Quantity;
    string Date_In;
    Node* link;
};

class List{ //Class for the linked list
    private:
        Node* Head; 	//head pointer
        Node* Tail; 	//Tail pointer
        int CurrentID; //Counter for how many IDs currently exist
    public:
        List(); //Constructor
        void add(string name,string category,int price,int quantity, string date = "-"); //Function to add new member of the list
        void del(int ID); 								//Function to delete a member of the list
        void show(); 									// Function to show the members of the list
        void editname(int id , string name);			// Function to edit the name of the item at ID
        void editcategory(int id , string category);	// Function to edit the category of the item at ID
        void editprice(int id , int price);				// Function to edit the price of the item at ID
        void editquantity(int id , int quantity);		// Function to edit the category of the item at ID
        void sort(int choice); 							//Function to sort the members of the list
        void search(string name = "-",int entry = 0); 	//Function to search the members of the list using certain key
        string rename(string nane);						// Function to generalize the word format (First letter are capitalized and rest are minimized
        int getCurrentID(); 							//Function that gets the value of CurrentID
        void save(string filename); 					// Function to save the values in the linked list into a txt file
        void load(string filename);						// Function to load the values on txt file to the linked list
        string init_menu(); 							// Function of initial menu of the app
        bool check(string name);						// Function to check wether a certain string is present in a file
        string new_date();								// Function that returns the current date as strings
        void show_upper();								//Function that prints out the header
        void swap(Node* temp); 							// function to swap the value of 2 nodes
        void format(Node* temp);						// function to print out the values of an item in the table format
    	~List();// Destructor
        
};
//ADT

#endif
