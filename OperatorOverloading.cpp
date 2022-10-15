#include<iostream>
using namespace std;
class Format{
	int date, month, year;
	public:
		void yearcorr(){
			if (month > 12){
				year = year + 1;
				month = month - 12;
			}
			correction();
		}
		
		void correction(){
			if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
				while (date>31){
					month = month+1;
					date = date - 31;
					yearcorr();
				}
			}
			if (month==2){
				if (year%400==0||year%4==0){
					while (date>29){
						month = month + 1;
						date = date - 29;
					}
				}
				else {
					while (date>28){
						month = month + 1;
						date = date -28;
					}
				}
			}
			if (month==4||month==6||month==9||month==11){
				while (date>30){
					month = month + 1;
					date = date - 30;
				}
			}
		}
		
		void negyearcorr(){
			if (month < 1){
				year = year - 1;
				month = month + 12;
			}
			negcorr();
		}
		void negcorr(){
			if (month==5||month==7||month==10||month==12){
				while (date<=0){
					month = month-1;
					date = date + 30;
				}
			}
			if (month==1||month==8){
				while (date<=0){
					month = month-1;
					date = date + 31;
					negyearcorr();
				}
			}
			if (month==3){
				while (date<=0){
						month = month - 1;
						date = date + 29;
				}
			}
			if (month==2){
				if (year%400==0||year%4==0){
					while (date<=0){
						month = month - 1;
						date = date + 31;
					}
				}
				else {
					while (date<=0){
						month = month - 1;
						date = date + 31;
					}
				}
			}
			if (month==4||month==6||month==9||month==11){
				while (date<=0){
					month = month - 1;
					date = date + 31;
				}
			}
		}
		void get_date(){
			cout<<"\nEnter the Date: ";
			cin>>date;
			cout<<"Enter the Month: ";
			cin>>month;
			cout<<"Enter the Year: ";
			cin>>year;
			yearcorr();
		}
		
		void display(){
			cout<<endl<<date<<"/"<<month<<"/"<<year<<endl;
		}
		
		void operator ++(){
			date = date+1;
			yearcorr();
			cout<<endl<<"The next date is: "<<date<<"/"<<month<<"/"<<year<<endl;
		}
		
		void operator --(){
			date = date-1;
			negyearcorr();
			cout<<endl<<"The previous date is: "<<date<<"/"<<month<<"/"<<year<<endl;
		}
};

int main(){
	Format d;
	int num;
	do{
		cout<<"\n1.To Enter a Date\n2.To Dispay The Date\n3.To see Next Date\n4.To See Previous Date\n5.Exit\n\nEnter your choice : ";
		cin>>num;
		switch(num){
			case 1:d.get_date();
				   d.display();
				   break;
			case 2:d.display();
				   break;
			case 3:++d;
				   break;
			case 4:--d;
				   break;
		}
	}while (num!=5);
	return 0;
}           
