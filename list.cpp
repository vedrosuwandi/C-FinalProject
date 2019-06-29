#include<iostream>
#include<fstream> //used for saving and loading data from text file
#include<sstream> //used for appending int into string
#include<string>
#include<iomanip> //used for setw(); to format the data display
#include<ctime>	  //used for adding time
#include "List.h"
using namespace std;

// Constructor 
List:: List(){ 
    Head = NULL; // set the data to NULL
    Tail = NULL;
    CurrentID = 1;
}
//Adding data to inventory
void List :: add(string name,string category,int price,int quantity, string date){ 
    Node* newnode = new Node(); // create new node
    newnode->ID = CurrentID; // get the data that includes ID , Name , Price , Category , Quantity and the time the item is imported
    newnode->Name = rename(name);
    newnode->Price = price;
    newnode->Category = rename(category);
    newnode->Quantity = quantity;
    newnode->link = NULL;
	if(date=="-"){
		date = new_date();
	}
	newnode->Date_In = date;
    if(Head == NULL){
        Head = newnode;
    }else if(CurrentID == 2){   
    	Tail = newnode;
        Head->link = Tail;
    }else{   
        Tail->link = newnode;
        Tail = newnode;
	}	
    CurrentID++; // as the item added the ID is keep increasing or auto increment
}
// Delete Data
void List ::del(int ID){ // This function delete data based on ID selected
	int temp_id = 1;
    Node* temp;
    Node* templink;
    temp = Head;
    templink = Head->link;
    if(ID == 1){ // Delete the first in the list
        delete temp;
        Head = templink;
        List::CurrentID--; // the total ID decreased by one
        while (temp!= NULL){ // Reset the ID
        	temp->ID = temp_id;
        	temp = temp->link;
        	temp_id++;
		}
        cout<<"Item successfully deleted.";
    }else if (ID > 1 || ID <= List::CurrentID){ 
        for(int i = 2 ; i <= ID-1 ; i++){
            if(temp != NULL){
                temp = temp->link;
                templink = templink->link;
            }
        }
        temp->link = templink->link;
        delete templink;
		List::CurrentID--; // the total ID decreased by one
        temp=Head;
        while (temp!= NULL){ // Reset the ID
        	temp->ID = temp_id;
        	temp = temp->link;
        	temp_id++;
		}
		cout<<"Item successfully deleted."; 
    }else{
    	cout<< "ID not found. Please check again";
	}
	cout<<endl<<endl;
}
// Print out the data
void List :: show(){ // Show data 
	Node* temp;
    temp = Head;
    show_upper();
    if(CurrentID == 1){
    	cout<< "No data available";
	}else{
		while(temp){
	        format(temp); // validate the Data's first letter in Capital
        	temp = temp->link;
    	}
	}
    
    cout << endl;
}
// Sorting Data based on  Name, ID, Category, Price, Quantity, or Date Inserted
void List :: sort(int choice){ 
	Node* temp;
    int curr_id = List::CurrentID;
    curr_id *= curr_id;
	switch(choice){
		case 1://name
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->Name > temp->link->Name){	
						swap(temp);
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
		case 2: //category
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->Category >= temp->link->Category){	
						swap(temp);
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
		case 3: //price
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->Price >= temp->link->Price){	
						swap(temp);
		    			
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
			case 4: //quantity
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->Quantity >= temp->link->Quantity){	
						swap(temp);
		    			
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
		case 5: //date
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->Date_In > temp->link->Date_In){	
						swap(temp);
		    			
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
			case 6: //id
			for (int i = 0;i<curr_id;i++){
				temp = Head;
				while (temp->link != NULL){
					if (temp->ID >= temp->link->ID){	
						swap(temp);
					}
					temp = temp->link; //advance to next node
				}
			}
			break;
	}
	
	
}
// Edit data based on Name
void List :: editname(int id , string name){
    Node* temp;
    temp = Head;
    while(temp != NULL){ // if the data isn't NULL
        if(temp->ID == id){ // check the data by ID
            temp->Name = rename(name);
            temp->Date_In = new_date();
        break;
		}
        temp = temp->link;
    }
}
// Edit data based on Category
void List :: editcategory(int id , string category){
    Node* temp;
    temp = Head;
    while(temp != NULL){
        if(temp->ID == id){
            temp->Category = rename(category);
            temp->Date_In = new_date();
            break;
        }
        temp = temp->link;
    }
}
// Edit data based on Price
void List :: editprice(int id , int price){
	if (price<0){
		cout<<"Invalid Price"<<endl;
	}else{
		Node* temp;
	    temp = Head;
	    while(temp != NULL){
	        if(temp->ID == id){
	            temp->Price = price;
	            temp->Date_In = new_date();
	            break;
	        }
	        temp = temp->link;
	    }
	}
    
}
// Edit data based on Quantity
void List :: editquantity(int id , int quantity){
    if (quantity<0){
		cout<<"Invalid Quantity"<<endl;
	}else{
		Node* temp;
	    temp = Head;
	    while(temp != NULL){
	        if(temp->ID == id){
	            temp->Quantity = quantity;
	            temp->Date_In = new_date();
	            break;
	        }
	        temp = temp->link;
	    }
	}
}
// To Show the Column Name
void List:: show_upper(){
	// setw -> set width 
	cout << "+===================================================================+" << endl;
    cout << "|" <<setw(3)<<"ID" << "|";
	cout << setw(12)<<"Name" << "|";
	cout << setw(12)<<"Category" << "|";
	cout << setw(12)<<"Price" << "|";
	cout << setw(8)<<"Quantity" << "|";
	cout << setw(15)<<"Last Modified" << "|" << endl;
	cout << "+===================================================================+" << endl;
}
// Swapping the data 
void List:: swap(Node* temp){
	int tempID, tempPrice, tempQuantity;
    string tempName, tempCategory, tempDate_In;
    int tempID_big, tempPrice_big, tempQuantity_big;
    string tempName_big, tempCategory_big, tempDate_In_big;
	tempID = temp->link->ID;
	tempName = temp->link->Name;
	tempCategory = temp->link->Category;
	tempPrice = temp->link->Price;
	tempQuantity = temp->link->Quantity;
	tempDate_In = temp->link->Date_In; //Stores the smaller value
	
	tempID_big = temp->ID;
	tempName_big = temp->Name;
	tempCategory_big = temp->Category;
	tempPrice_big = temp->Price;
	tempQuantity_big = temp->Quantity;
	tempDate_In_big = temp->Date_In; //Stores the bigger value
	
	temp->link->ID = tempID_big;
	temp->link->Name = tempName_big;
	temp->link->Category = tempCategory_big;
	temp->link->Price = tempPrice_big;
	temp->link->Quantity = tempQuantity_big;
	temp->link->Date_In  = tempDate_In_big; //Swaps the bigger value forwards
	
	temp->ID = tempID;
	temp->Name = tempName;
	temp->Category = tempCategory;
	temp->Price = tempPrice;
	temp->Quantity = tempQuantity;
	temp->Date_In = tempDate_In; //Swaps the smaller value backwards
}
// Search Data based on  Name, Category. ID, Price,  quantity
void List :: search(string name,int entry){ 
	int count = 0;
	name = rename(name);
	Tail = Head;
	cout<<"Search Results:"<<endl;
	if(name!="-"){
		cout<<"In Name:"<<endl;
		show_upper();
		while (Tail!= NULL){
			if (Tail->Name == name){
				count++;	
				format(Tail);
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){//If name not found
			cout<<"Sorry, No such item exist"<<endl;
		}
		Tail = Head;
		count = 0;
		cout<<endl<<"In Category: "<<endl;
		show_upper();
		while (Tail != NULL){
			if (Tail->Category == name){
				count++;
				format(Tail);
		        
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){
			cout<<"Sorry, No such category exist"<<endl<<endl;
		}
				
		Tail = Head;
		count = 0;
		cout<<endl<<"In Date Modified: "<<endl;
		show_upper();
		while (Tail != NULL){
			if (Tail->Date_In == name){
				count++;
				format(Tail);
		        
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){
			cout<<"Sorry, No such item exist"<<endl<<endl;
		}
	}
	if(entry!= 0){
		count = 0;
		Tail = Head;
		cout<<"Search Results:"<<endl;
		cout<<"In ID:"<<endl;
		show_upper();	
		while (Tail != NULL){
			if (Tail->ID == entry){
				count++;	
				format(Tail);		        
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){
			cout<<"Sorry, No such item exist"<<endl;
			}
		Tail = Head;
		count = 0;
		cout<<endl<<"In Price: "<<endl;
		show_upper();
		while (Tail != NULL){
			if (Tail->Category == name){
				count++;	
				format(Tail);
		        
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){
			cout<<"Sorry, No such item exist"<<endl<<endl;
		}	
		count = 0;
		Tail = Head;
		cout<<"Search Results:"<<endl;
		cout<<"In Quantity:"<<endl;
		show_upper();
		while (Tail != NULL){
			if (Tail->ID == entry){
				count++;	
				format(Tail);
		        
			}
			Tail = Tail->link; //advance to next node
		}
		if (count == 0){
			cout<<"Sorry, No such item exist"<<endl;
		}
		
	}
}
// Save File
void List:: save(string filename){
	string save;
	ofstream file;
	file.open("saves.txt",ios::app);
	if(check(filename)== false){
		file<<endl<<filename;
	}
	file.close();
	
	filename += ".txt";
	ofstream inFile;
	inFile.open(filename.c_str());
	Tail = Head;
	while(Tail!=NULL){
		inFile<<Tail->Name<<" "<<Tail->Category<<" "<<Tail->Price<<" "<<Tail->Quantity<<" "<<Tail->Date_In<<endl;
		Tail = Tail->link;
	}
	inFile.close();
	
}
// Load File
void List:: load(string filename){ 
	string name, cat, date;
	int price, quan,count;
	
	filename+=".txt";
	ifstream countline(filename.c_str());
	while (getline(countline, name))
        count++;
    countline.close();
    
	ifstream loadfile(filename.c_str());
	
    for (int i = 0;i<count;i++){
    	loadfile >> name >> cat >> price >> quan >> date ;
        add(name, cat, price, quan,date);
}
    loadfile.close();

}
// set the width between the border with the data
void List::format(Node* temp){
		cout << "|" <<setw(3)<<temp->ID << "|";
		cout << setw(12)<<temp->Name << "|";
		cout << setw(12)<<temp->Category << "|";
		cout << setw(12)<<temp->Price << "|";
		cout << setw(8)<<temp->Quantity << "|";
		cout << setw(15)<<temp->Date_In << "|" << endl;
}
// Validate the First Letter in Capital
string List:: rename(string name){//turns string input into Capitalied first letter and lower case the rest
	name[0] = toupper(name[0]);
	for (int i=1;i<name.length();i++){
		name[i] = tolower(name[i]);
	};
	return name;
}
// Function that returns current date as string
string List:: new_date(){
	int day, month, year;
	stringstream ss;
	time_t t = time (NULL); //Create the time variable
	tm* timePtr = localtime(&t);//Store the time value inside a struct
	day = timePtr->tm_mday;
	month=timePtr->tm_mon+1;
	year=timePtr->tm_year+1900;
	ss<<day;
	ss<<"-";
	if(month<10){
		ss<<"0";	
	}
	ss<<month;
	ss<<"-";
	ss<<year;
	return ss.str();
}
// Getter for CurrentID
int List :: getCurrentID(){
    return CurrentID;
}
// Check Data whether the data exist or not
bool List:: check(string name){
	string in_file;
	ifstream file;
	file.open("saves.txt");
	while(file>>in_file){
		if(name==in_file){
			return true;
		}
	}
	file.close();
	return false;
}
// The Menu for Creating and Open a file 
string List:: init_menu() {
	int choice, count = 0;
	bool run = true;
	string filename,input;
	ifstream infile;
	while(run){
    	cout << "+=====================+" << endl;
        cout << "       INVENTORY       " << endl;
        cout << "+=====================+" << endl;
        cout << "Welcome. Please choose from the option below: " << endl;
        cout << "1. Create new data" << endl;
        cout << "2. Load data" << endl;
        cout << "0. Exit App " << endl;
        cout << "Choice : "<< endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "+==========================+" << endl;
                cout << "       CREATE NEW FILE     " << endl;
                cout << "+==========================+" << endl;
                cout << "Insert FIle name : " ;
                cin >> filename;
                if(check(filename)){
                	cout << endl<< "FILE '"<<filename<<".txt' ALREADY EXIST!"<<endl;
                	return filename;
				}else{
					cout << endl<< "FILE '"<<filename<<".txt' SUCCESSFULLY CREATED!"<< endl;
                	return filename;
				}
                
                break;
            case 2:
                cout << "+==========================+" << endl;
                cout << "          LOAD FILE         " << endl;
                cout << "+==========================+" << endl;
        		
				infile.open("saves.txt");
				cout << "Available files : "<<endl ;
			    while(infile >> input){
					cout << input<<endl;
					count++;
				};
				if(count == 0){
					cout << "Sorry, no savefiles found. Creating new file..."<< endl<<endl;
					filename = "temp";
					return filename;
				}else{
					cout << "Insert File name : " ;
                	cin >> filename;
            		while(infile >> input){
						if(filename == input){
	            			load(filename);
	            			return filename;
					}
					cout<<"Wrong filename."<<endl;
				}
                
                break;
            case 0:
                cout << "+==========================+" << endl;
                cout << "          EXIT APP          " << endl;
                cout << "+==========================+" << endl;
                cout << "Shutting down.." << endl;
                exit(0);
            }
	}
	infile.close();
	return filename;
}
}
// Destructor
List :: ~List(){
    while (Head != NULL) // as long as the Head isn't empty
    {
        Tail = Head;
        Head = Tail->link;
        delete Head; // keep deleting until it's empty
    }
    
}

