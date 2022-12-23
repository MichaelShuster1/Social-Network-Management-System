#include "helper.h"
using namespace std;

void addNewUserToSystem(System& system)
{
	int year, month, day;
	string name;
	bool valid_date = false;
	bool valid_name = false;
	bool name_pending = false;

	cin.ignore();
	while (!valid_date || !valid_name)
	{
		if (!valid_name && !name_pending)
		{
			cout << "Please enter the name of the new user: ";
			getline(cin, name);
		}
		if (!valid_date)
		{
			cout << "Please enter the user's birth date in the following format : dd/mm/yyyy" << endl;
			cin >> day;
			cin.ignore();
			cin >> month;
			cin.ignore();
			cin >> year;
			cin.ignore();
		}
		try
		{
			system.addNewUser(Member(name, Date(year, month, day)));
			valid_date = true;
			valid_name = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			if (!valid_date)
			{
				if (strcmp(msg, "Incorrect birth date") == 0)
					name_pending = true;
				else
				{
					valid_date = true;
					name_pending = false;
				}
			}
		}

	}
}



void addNewPageToSystem(System& system)
{
	string name;
	bool isValidData = false;
	

	cin.ignore();
	while (!isValidData)
	{
		cout << "Please enter the name of the new page: ";
		getline(cin, name);
		try 
		{
			system.addNewPage(Fan_page(name));
			isValidData = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}	
}


void createNewStatus(Status** newStatus)
{
	string text;
	string tm;
	time_t curr_time;
	bool isValidData = false;

	cin.ignore();
	while (!isValidData)
	{
		cout << "Please enter your status: ";
		getline(cin, text);
		curr_time = time(NULL);
		tm = ctime(&curr_time);
		try
		{
			*newStatus = new Status(text, tm);
			isValidData = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
}


void printAllRegisteredEntitiesInSystem(System& system)
{
	system.printAllSystemMembers();
	cout << endl;
	system.printAllSystemPages();
}


void chooseOneMember(string& name)
{
	cout << "please enter the name of the member: ";
	cin.ignore();
	getline(cin, name);
	/*
	int choice;
	int size = system.getMembersSize();
	bool validInput;

	do
	{
		cout << "please choose the index of the member: " << endl;
		system.printAllSystemMembers();
		cout << "Enter your choice here: ";
		cin >> choice;
		if (1 <= choice && choice <= size)
			validInput = true;
		else
		{
			cout << "error: your choice needs to be a number between 1 and " << size << endl;
			validInput = false;
		}
	} while (validInput == false);
	
	return choice;
	*/
}


void chooseOnePage(string& name)
{
	cout << "please enter the name of the page: ";
	cin.ignore();
	getline(cin, name);
	/*
	int choice;
	int size = system.getPagesSize();
	bool validInput;

	do
	{
		cout << "Enter the index of the fan page: " << endl;
		system.printAllSystemPages();
		cout << "Enter your choice here: ";
		cin >> choice;
		if (1 <= choice && choice <= size)
			validInput = true;
		else
		{
			cout << "error: your choice needs to be a number between 1 and " << size << endl;
			validInput = false;
		}
	} while (validInput == false);

	return choice;
	*/
}


void choosePagesOrMembers(int& choice)
{
	bool isValidData = false;
	while (!isValidData)
	{
		cout << "enter 1 to choose a member" << endl;
		cout << "enter 2 to choose a fan page" << endl;
		cout << "please enter your choice here:  ";
		cin >> choice;
		if (choice == MEMBER || choice == FAN_PAGE)
			isValidData = true;
		else
			cout << "error:your choice needs to be the number 1 or 2 only!,please try again" << endl;
	}
}


void printAllFriendsOrFansEntity(System& system)
{
	int choice;
	string name;

	choosePagesOrMembers(choice);
	switch (choice)
	{
	case MEMBER:
		chooseOneMember(name);
		system.printAllFriendsOfMember(name);
		break;
	case FAN_PAGE:
		chooseOnePage(name);
		system.printAllFandsOfPage(name);
		break;
	default:
		break;
	}

}


void addNewStatusToFanPageOrMember(System& system)
{
	int choice;
	string name;
	Status* newStatus;

	choosePagesOrMembers(choice);
	createNewStatus(&newStatus);

	switch (choice)
	{
	case MEMBER:
		chooseOneMember(name);
		system.addNewStatusToMember(*newStatus, name);
		break;
	case FAN_PAGE:
		chooseOnePage(name);
		system.addNewStatusToFanPage(*newStatus, name);
		break;
	default:
		break;
	}
	delete newStatus;
}


void showAllStatusesOfAFanPageOrMember(System& system)
{
	int choice, index;
	string name;

	choosePagesOrMembers(choice);
	switch (choice)
	{
	case MEMBER:
		chooseOneMember(name);
		system.showAllStatusesOfAMember(name);
		break;
	case FAN_PAGE:
		chooseOnePage(name);
		system.showAllStatusesOfAFanPage(name);
		break;
	default:
		break;
	}

}


void ShowTenStatusesOfEachFriend(System& system)
{
	int index;
	string name;
	cout << "choose a member by entering their index number: " << endl;
	chooseOneMember(name);
	system.ShowTenLatestStatusesOfEachFriend(name);
}



void linkFriendshipInSystem(System& system)
{
	char choice;
	bool validInput = false, exit = false;
	string name1, name2;
	chooseOneMember(name1);
	cout << "second member:" << endl;
	chooseOneMember(name2);
	while (!validInput && !exit)
	{
		try
		{
			system.linkFriends(name1, name2);
			validInput = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			do {
				cout << "do you wish to try again?[y/n]: ";
				cin >> choice;

				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}
	}
	/*
	do
	{
		cout << "please choose the two members you want to link by entering their index number with following formant: index1 index2" << endl;
		system.printAllSystemMembers();
		cout << "please enter your choice here: ";
		cin >> index1;
		getchar();
		cin >> index2;
		if ((1 <= index1 && index1 <= size) && (1 <= index2 && index2 <= size))
		{
			try
			{
				system.linkFriends(index1 - 1, index2 - 1);
				validInput = true;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				do {
					cout << "do you wish to try again?[y/n]: ";
					cin >> choice;

					if (choice == NO)
						exit = true;
					else if (choice != YES)
						cout << "Invalid input, please enter y or n" << endl;
				} while (choice != NO && choice != YES);
			}
		}
		else
		{
			cout << "error: your choices needs to be a number between 1 and " << size << ",please try again" << endl;
		}


	} while (!validInput && !exit);
	*/

}


//bool checkValidInput(System& system,int index1, int index2)
//{
//	bool isVaild = true;
//	int size = system.getMembersSize();
//
//	if ((1 <= index1 && index1 <= size) && (1 <= index2 && index2 <= size))
//	{
//		if (index1 == index2)
//		{
//			cout << "error: you cant link a member with himself!" << endl;
//			isVaild = false;
//		}
//		else if (system.areFriendsCheck(index1 - 1, index2 - 1))
//		{
//			cout << "error: the members you chose are already linked!" << endl;
//			isVaild = false;
//		}
//	}
//	else
//	{
//		cout << "error: your choices needs to be a number between 1 and " << size << ",please try again" << endl;
//		isVaild = false;
//	}
//		
//
//	return isVaild;
//}


void unLinkFriendshipInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;
	string name1,name2;

	cout << "user from which you want to unlink a friend: " << endl;
	chooseOneMember(name1);
	cout << "friend you want to delete: " << endl;
	chooseOneMember(name2);
	try
	{
		system.unLinkFriends(name1, name2);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}


int chooseOneFriendOfAMember(System& system,int index)
{
	int choice, size = system.getFriendsSizeOfAMember(index);
	bool validInput;
	if (size != EMPTY)
	{
		do
		{
			cout << "choose the friend you want to unlink: " << endl;
			system.printAllFriendsOfMember(index);
			cout << "Enter your choice here: ";
			cin >> choice;
			if (1 <= choice && choice <= size)
				validInput = true;
			else
			{
				cout << "error: your choice needs to be a number between 1 and " << size << endl;
				validInput = false;
			}
		} while (validInput == false);

		return choice;
	}
	else
	{
		cout << "the user you chose has no friends to unlink from" << endl;
		return NOT_FOUND;
	}

}


void addFanToPageInSystem(System& system)
{
	bool isValidData=false , exit = false;
	char choice;
	string name_page, name_member;
  

	while (!isValidData&&!exit)
	{
		cout << "the fan page you want to add a member as a fan to : " << endl;
		chooseOnePage(name_page);
		cout << "the memeber you wish to add to a fan page: " << endl;
		chooseOneMember(name_member);

		try
		{
			system.addFanToAPage(name_page, name_member);
			isValidData = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
			do {
				cout << "do you wish to try again [y/n]:";
				cin >> choice;
				if (choice == NO)
					exit = true;
				else if (choice != YES)
					cout << "Invalid input, please enter y or n" << endl;
			} while (choice != NO && choice != YES);
		}

	}

}


void removeFanFromPageInSystem(System& system)
{
	string name_page, name_fan;
	cout << "choose a fan page from which you want to unlink a fan: " << endl;
	chooseOnePage(name_page);
	chooseOneMember(name_fan);
	try
	{
		system.removeFanFromAFanPage(name_page, name_fan);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}


int chooseOneFanOfAPage(System& system,int index)
{
	int choice, size = system.getFansSizeofAPage(index);
	bool validInput;
	if (size != EMPTY)
	{
		do
		{
			cout << "choose the fan you want to unlink:  " << endl;
			system.printAllFandsOfPage(index);
			cout << "Enter your choice here: ";
			cin >> choice;
			if (1 <= choice && choice <= size)
				validInput = true;
			else
			{
				cout << "error: your choice needs to be a number between 1 and " << size << endl;
				validInput = false;
			}
		} while (validInput == false);
		return choice;
	}
	else
	{
		cout << "the page you chose dont have fans to delete" << endl;
		return NOT_FOUND;
	}

}

void printMenu()
{
	cout << "welcome to the system's menu ,please select an action" << endl;
	cout << "1- add a new member" << endl;
	cout << "2- add a new fan page" << endl;
	cout << "3- add a new status for a member/fan page" << endl;
	cout << "4 -show all statuses of a member/fan page" << endl;
	cout << "5- show 10 most recent statuses of member's friends" << endl;
	cout << "6 -link two members" << endl;
	cout << "7- unlink two members" << endl;
	cout << "8- add a fan to fan page" << endl;
	cout << "9- delete a fan from fan page" << endl;
	cout << "10- show all entities that are registered to the system" << endl;
	cout << "11- show all friends of a member/show all fans of a fan page" << endl;
	cout << "12- exit" << endl;
	cout << "please enter your choice here:  ";
}


bool processChoice(System& system,int choice)
{
	bool exit = false;
	switch (choice)
	{

	case ADD_NEW_USER:
		addNewUserToSystem(system);
		break;

	case ADD_NEW_PAGE:
		addNewPageToSystem(system);
		break;

	case ADD_NEW_STATUS:
		addNewStatusToFanPageOrMember(system);
		break;

	case SHOW_ALL_STATUSES:
		showAllStatusesOfAFanPageOrMember(system);
		break;

	case SHOW_TEN_STATUSES:
		ShowTenStatusesOfEachFriend(system);
		break;

	case LINK_FRIENDS:
		linkFriendshipInSystem(system);
		break;

	case UNLINK_FRIENDS:
		unLinkFriendshipInSystem(system);
		break;

	case ADD_FAN:
		addFanToPageInSystem(system);
		break;

	case REMOVE_FAN:
		removeFanFromPageInSystem(system);
		break;

	case PRINT_ALL_ENTITIES:
		printAllRegisteredEntitiesInSystem(system);
		break;

	case PRINT_ALL_FANS_FRIENDS:
		printAllFriendsOrFansEntity(system);
		break;

	case EXIT:
		exit = true;
		cout << "Good bye" << endl;
		break;

	default:
		cout << "please choose a number from 1 to 12 only"<< endl;
		break;
	}
	return exit;
}