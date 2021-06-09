#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 
#include <string>
#include <iomanip>

using namespace std;

ofstream dataFileOut;
ifstream dataFileIn;
vector<vector<string>> data;

void collectData(){
	string line;
	string str;
	int dataIndex = 0;
	vector<string> vecTemp;
	dataFileIn.open("contactManager.txt");
	
	if(dataFileIn.is_open()){
		cout<<"Open file successfully!"<<endl;
		string str;
		while(getline(dataFileIn, line)){
			stringstream input(line);
			data.push_back(vecTemp);
			while(input>>str){
				data[dataIndex].push_back(str);
			}
			dataIndex++;
		}
	} else {
		cout<<"Failed to open file!"<<endl;
	} 
	dataFileIn.close();
}

void createContactManagerTxt(){
	vector<string> vecTemp;
	vecTemp.push_back("Name");
	vecTemp.push_back("PhoneNo.");
	vecTemp.push_back("Email");
	vecTemp.push_back("favorite");
	data.push_back(vecTemp);
}

void listAll(){
	for(int i = 0; i < data.size(); i++){
		cout<<left<<setw(10)<<data[i][0]<<left<<setw(15)<<data[i][1]<<left<<setw(25)<<data[i][2]<<left<<setw(10)<<data[i][3]<<endl;
    }
}

void addMember(){
	string memberName;
	string memberPhoneNo;
	string memberEmail;
	string favorite;
	vector<string> vecTemp;
	
	cout<<"Please input Name : ";
	cin>>memberName;
	cout<<"Please input Phone No. : ";
	cin>>memberPhoneNo;
	cout<<"Please input Email : ";
	cin>>memberEmail;
	cout<<"Please input favorite (yes/no): ";
	cin>>favorite;
	
	vecTemp.push_back(memberName);
	vecTemp.push_back(memberPhoneNo);
	vecTemp.push_back(memberEmail);
	vecTemp.push_back(favorite);
	data.push_back(vecTemp);
}

void deleteMember(){
	string memberName;
	int index;
	cout<<"Which member do you want to delete (Please enter the name) : ";
	cin>>memberName;
	for(int i = 0; i < data.size(); i++){
		if(data[i][0] == memberName) {
			index = i;
			break;	
		}
	}
	data.erase(data.begin()+index);
}

void EditMember(){
	string memberName;
	string modified;
	int item;
	int index;
	cout<<"Which member do you want to edit (Please enter the name) : ";
	cin>>memberName;
	for(int i = 0; i < data.size(); i++){
		if(data[i][0] == memberName) {
			index = i;
			break;
		}
	}
	cout<<"Which item needs to be modified ?"<<endl;
	cout<<"Press[1] for Phone No."<<endl;
	cout<<"Press[2] for Email"<<endl;
	cout<<"Press[3] for favorite"<<endl;
	cin>>item;
	
	cout<<"Modified "<<data[index][item]<<" into : ";
	cin>>modified;
	data[index][item] = modified;
}

void searchMember(){
	string memberName;
	cout<<"Which member do you want to search : ";
	cin>>memberName;
	for(int i = 0; i < data.size(); i++){
		if(data[i][0] == memberName) {
			cout<<left<<setw(10)<<data[0][0]<<left<<setw(15)<<data[0][1]<<left<<setw(25)<<data[0][2]<<left<<setw(10)<<data[0][3]<<endl;
			cout<<left<<setw(10)<<data[i][0]<<left<<setw(15)<<data[i][1]<<left<<setw(25)<<data[i][2]<<left<<setw(10)<<data[i][3]<<endl;
			break;
		} else if(i == data.size()-1) {
			cout<<"Not found"<<endl;
		}
	}
	
}

void selectFavorite(){
	bool flag = false;
	cout<<left<<setw(10)<<data[0][0]<<left<<setw(15)<<data[0][1]<<left<<setw(25)<<data[0][2]<<left<<setw(10)<<data[0][3]<<endl;
	for(int i = 0; i < data.size(); i ++){
		if(data[i][3] == "yes"){
			flag = true;
			cout<<left<<setw(10)<<data[i][0]<<left<<setw(15)<<data[i][1]<<left<<setw(25)<<data[i][2]<<left<<setw(10)<<data[i][3]<<endl;
		}
	}
	if(flag == false) {
		
		cout<<"Not found"<<endl;
	}
}

void storeInTxt(){
	dataFileOut.open("contactManager.txt");
	for(int i = 0; i < data.size(); i++){
		dataFileOut<<left<<setw(10)<<data[i][0]<<left<<setw(15)<<data[i][1]<<left<<setw(25)<<data[i][2]<<left<<setw(10)<<data[i][3]<<endl;
	}
	dataFileOut.close();
}

int main(){
	int input = 1;
	collectData();
	if(data.empty()) createContactManagerTxt();
	
	cout<<"Press[0] to save & exit"<<endl;
	cout<<"Press[1] to execute listAll"<<endl;
	cout<<"Press[2] to execute addMember"<<endl;
	cout<<"Press[3] to execute deleteMember"<<endl;
	cout<<"Press[4] to execute EditMember"<<endl;
	cout<<"Press[5] to execute searchMember"<<endl;
	cout<<"Press[6] to execute selectFavorite"<<endl;
	
	while(input){
		cout<<endl;
		cout<<"Please press button : ";
		cin>>input;
		cout<<endl;
		if(input == 0) break;
		if(input == 1) listAll();
		if(input == 2) addMember();
		if(input == 3) deleteMember();
		if(input == 4) EditMember();
		if(input == 5) searchMember();
		if(input == 6) selectFavorite();
	}

	storeInTxt();
	return 0;
} 
