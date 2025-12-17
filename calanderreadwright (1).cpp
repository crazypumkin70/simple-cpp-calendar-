#include<bits/stdc++.h>
#include<stdio.h>
#include <windows.h>
#include<iostream>
#include <bits/basic_string.h>
#include<fstream>
#include<string.h>
#include<string.h>
#include<direct.h>
#include<dirent.h>

using namespace std;
int space(int year) {
	int x;
	x=((((year-1)*365)+(year-1)/4)-((year-1)/100)+(year/400))%7;
	return x;
}
int main() {
	int days[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	string months[13]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
	int year , month;
	string name;
	char cyear[4];
	cout<<"Enter the calander year: ";
	cin>>year;
	cout<<"\nEnter again to confirm: ";
	cin>>cyear;


	if(cyear[0]-48==year/1000) {
		if(cyear[1]-48==((year%1000)/100)) {
			if(cyear[2]-48==(year%100)/10) {
				if(cyear[3]-48==year%10) {
					cout<<"Year matched\n";
				} else {
					cout<<"invalid year\n";
					return(0);
				}
			} else {
				cout<<"invalid year\n";
				return(0);
			}
		} else {
			cout<<"invalid year\n";
			return(0);
		}
	} else {
		cout<<"invalid year\n";
		return(0);
	}











	cout<<"Enter the month: \n";
	cout<<"\tEnter 1 for JANUARY\n\tEnter 2 for FEBRUARY\n\tEnter 3 for MARCH\n\tEnter 4 for APRIL\n\tEnter 5 for MAY\n\tEnter 6 for JUNE\n\tEnter 7 for JULY\n\tEnter 8 for AUGUST\n\tEnter 9 for SEPTEMBER\n\tEnter 10 for OCTOBER\n\tEnter 11 for NOVEMBER\n\tEnter 12 for DECEMBER\n\t";
	cout<<"My Choice is: ";
	cin>>month;

	system("CLS");
	if((year%4==0&&year%100!=0)||(year%400!=0)) {
		days[1]=29;
	}
	int gap=space(year);





	cout<<"\t***************************************************\n";


	for(int k=0; k<12; k++) {
		if(k+1==month) {
			cout<<"\n\t\t\t\t"<<months[k]<<"\n";
			cout<<"\t\t\t----------------------\n";
			cout<<"\tsun\tmon\ttue\twed\tthu\tfri\tsat\n";

			for(int j=0; j<=gap; j++) {
				cout<<"\t";
			}
			for(int i=0; i<days[k]; i++) {
				cout<<i+1<<"\t";
				if(++gap>6) {
					gap=0;
					cout<<"\n\t";
				}

			}
		} else {



			for(int i=0; i<days[k]; i++) {

				if(++gap>6) {
					gap=0;

				}

			}
		}


	}
	cout<<"\n\n\t***************************************************\n\n\n";







	cout<<"\t Event this month\n";


	if(month==1) {
		//char s[300]="January.txt";
		mkdir(cyear);   //mkdir("1994");
		chdir(cyear);// change directory


		fstream planner;
		planner.open("january.txt",ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();


			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";

			int choice;
			do {
				planner.open("january.txt",ios::in|ios::out|ios::app);
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {


						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					//	planner.close();
					//	planner.open("january.txt",ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	} else if(month==2) {
		char s[300]="February.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {


			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;

					if((year%100==0&&year%400!=0)||(year%4!=0)) {
						if(dt>28) {
							cout<<"Invalid date...";
							break;
						} else {


							cout<<"Enter the event name:\n";
							cin.ignore();
							getline(cin,name);
							planner<<"\t ";
							planner<<dt;
							planner<<":\t";
							planner<<name;
							planner<<"\n";
							planner.close();
						}
						planner.close();
						planner.open(s,ios::in|ios::out|ios::app);
					}
				}

				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);
		}
		planner.close();
	}


	else if(month==3) {
		char s[300]="March.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	} else if(month==4) {
		//char s[300]="April.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open("April.txt",ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open("April.txt",ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>30) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open("April.txt",ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();


	} else if(month==5) {
		char s[300]="May.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	} else if(month==6) {
		char s[300]="June.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>30) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	} else if(month==7) {
		char s[300]="July.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	} else if(month==8) {
		char s[300]="August.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();


	} else if(month==9) {
		char s[300]="September.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>30) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();


	} else if(month==10) {
		char s[300]="October.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();


	} else if(month==11) {
		char s[300]="November.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>30) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();


	} else if(month==12) {
		char s[300]="december.txt";
		mkdir(cyear);
		chdir(cyear);
		fstream planner;
		planner.open(s,ios::in|ios::out|ios::app);
		if(!planner.is_open()) {
			cout<<"false";
		} else {

			cout<<"\t Date\tEvent\n";
			cout<<"\t------\t------\n";


			string redln;
			while(getline(planner,redln)) {

				cout<<redln<<"\n";
			}
			planner.close();

			cout<<"\n\n\tDo you want to add event in this month?\n";
			cout<<"1 for yes\n0 for no\n";
			planner.open(s,ios::in|ios::out|ios::app);
			int choice;
			do {
				cout<<"Your choice is: ";
				cin>>choice;
				if(choice==0) {
					break;
				}
				if(choice==1) {
					int dt;
					cout<<"Enter the date(example-  25): ";
					cin>>dt;
					if(dt>31) {
						cout<<"Invalid date...";
						break;
					} else {

						cout<<"Enter the event name:\n";
						cin.ignore();
						getline(cin,name);
						planner<<"\t ";
						planner<<dt;
						planner<<":\t";
						planner<<name;
						planner<<"\n";
						planner.close();
					}
					planner.close();
					planner.open(s,ios::in|ios::out|ios::app);

				}
				cout<<"do you want to add more events?\n";
				cout<<"1 for yes\n0 for no\nyout choice: ";
			} while(choice==1);

		}
		planner.close();

	}





}


