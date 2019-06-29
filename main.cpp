#include<iostream>
#include<fstream>
#include<string>
#include "List.cpp"
using namespace std;

// Menu after a file is created or opened
int menu(){
    List list;
    int choice, id, price, quantity;
    string name, category, search;
	string filename = list.init_menu();
	cout<<"Current File :"<< filename<<".txt"<<endl;
	list.load(filename);
    
    while(true){
        list.show();
        cout << "+=====================+" << endl;
        cout << "       INVENTORY       " << endl;
        cout << "+=====================+" << endl;
        cout << "1. Add " << endl;
        cout << "2. Delete " << endl;
        cout << "3. Edit " << endl;
        cout << "4. Sort " << endl;
        cout << "5. Search " << endl; 
        cout << "6. Save" << endl;
        cout << "7. Load Another File" << endl;
        cout << "0. Exit"<<endl;
        cout << "Choice:";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "+=====================+" << endl;
                cout << "         ADD      " << endl;
                cout << "+=====================+" << endl;
                cout << "Insert Name : " ;
                cin >> name;
                cout << "Insert Category : ";
                cin >> category;
                cout << "Insert Price : ";
                cin >> price;
                cout << "Insert Quantity : ";
                cin >> quantity;
                list.add(name , category , price , quantity);
                cout << endl;
                break;
            case 2:
                cout << "+=====================+" << endl;
                cout << "        DELETE       " << endl;
                cout << "+=====================+" << endl;
                cout << "Please Insert the ID : ";
                cin >> id;
                list.del(id);
                cout << endl;
                break;
            case 3:
                int sub;
                cout << "+=====================+" << endl;
                cout << "        EDIT       " << endl;
                cout << "+=====================+" << endl;
                cout << "Insert ID : " ;
                cin >> id;
                if(id > list.getCurrentID()-1|| id<=0){
                    cout << "There is No item in " << id << endl;
                }else{
                    cout << "1. Edit Name " << endl;
                    cout << "2. Edit Category " << endl;
                    cout << "3. Edit Price " << endl;
                    cout << "4. Edit Quantity "<< endl;
                    cout << "Choice :" << endl;
                    cin >> sub;
                    if(sub == 1){
                        cout << "Insert new Name : " ;
                        cin >> name;
                        list.editname(id, name);
                    }else if(sub == 2){
                        cout << "Insert new Category : " ;
                        cin >> category;
                        list.editcategory(id,category);
                    }else if(sub == 3){
                        cout << "Insert new Price : " ;
                        cin >> price;
                        list.editprice(id,price); 
                    }else if(sub == 4){
                        cout << "Insert new Quantity : " ;
                        cin >> quantity;
                        list.editquantity(id , quantity);
                    }else{
                        cout << "Wrong Input !!" << endl;
                    }
                    cout << endl;
                }break;
                cout << endl; 
            case 4:
                cout << "+=====================+" << endl;
                cout << "         SORT       " << endl;
                cout << "+=====================+" << endl;
                cout << "1. Sort by Name " << endl;
                cout << "2. Sort by Category " << endl;
                cout << "3. Sort by Price " << endl;
                cout << "4. Sort by Quantity "<< endl;
                cout << "5. Sort by Date Modified " << endl;
                cout << "6. Sort by ID "<< endl;
                cout << "0. Cancel "<< endl;
                cout << "Choice :" << endl;
                cin >> sub;
                if(sub == 1){
                    list.sort(1);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 2){
                    list.sort(2);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 3){
                    list.sort(3);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 4){
                    list.sort(4);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 5){
                    list.sort(5);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 6){
                    list.sort(6);
                    cout <<"Sorted successfully!"<<endl;
                }else if(sub == 0){
                    cout <<"Sorting cancelled!" <<endl;
                    break;
                }else{
                    cout << "Wrong Input !!" << endl;
                }
                break;
            case 5:
            	
                cout << "+=====================+" << endl;
                cout << "       SEARCH       " << endl;
                cout << "+=====================+" << endl;
            	cout << "Select search category: "<<endl;
            	cout << "1. Name, Category, Date Modified "<<endl;
            	cout << "2. ID, Price, Quantity "<<endl;
            	cin>> choice;
            	switch(choice){
            		case 1:
            			cout << "Input search key: (Dates uses DD-MM-YYYY format)"<<endl;
            			cin>>search;
            			list.search(search);
            			break;
            		case 2:
            			cout << "Input search key: "<<endl;
            			cin>> choice;
            			list.search("-",choice);
            			break;
				}
                break;
            case 6:
                cout <<"+=====================+" << endl;
                cout <<"          SAVE         " << endl;
                cout <<"+=====================+" << endl;
                list.save(filename);
                cout <<"File saved!" << endl;
                break;
			case 7:
				list.save(filename);
				menu();
			case 0 :
				list.save(filename);
				exit(0);
            default:
                cout << "Error 404" << endl;
                break; 
        }
    }
}

int main(){
    menu();
}
