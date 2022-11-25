#include "helper.h"

void addNewUserToSystem(System& system)
{
	int year, month, day;
	char name[NAME_LEN];
	Member* new_user;

	cout << "Please enter the name of the new user: ";
	getchar();
	cin.getline(name, NAME_LEN);
	while (system.checkIfExistNameUser(name) == true)
	{
		cout << "the name is already taken!" << endl;
		cout << "Please enter the name of the new user: ";
		cin.getline(name, NAME_LEN);
	}


	cout << "Please enter the user's bith date in the following formt : dd/mm/yyyy" << endl;
	cin >> day;
	getchar();
	cin >> month;
	getchar();
	cin >> year;
	new_user = new Member(name, Date(year, month, day));
	system.addNewUser(new_user);
}



void addNewPageToSystem(System& system)
{
	char name[NAME_LEN];
	Fan_page* new_page;

	cout << "Please enter the name of the new page: ";
	getchar();
	cin.getline(name, NAME_LEN);
	while (system.checkIfExistNamePage(name) == true)
	{
		cout << "the name is already taken!" << endl;
		cout << "Please enter the name of the new page: ";
		cin.getline(name, NAME_LEN);
	}


	new_page = new Fan_page(name);
	system.addNewPage(new_page);
}


Status* createNewStatus()
{
	char text[254];
	char* tm;
	time_t curr_time;
	Status* newStatus;

	cout << "Please enter your status: ";
	getchar();
	cin.getline(text, 254);
	curr_time = time(NULL);
	tm = ctime(&curr_time);

	newStatus = new Status(text, tm);
	return newStatus;
}


void printAllRegisteredEntitiesInSystem(System& system)
{
	system.printAllSystemMembers();
	system.printAllSystemPages();
}


int chooseOneMember(System& system)
{
	int choice;
	system.printAllSystemMembers();
	cout << "Enter the index of the member: ";
	cin >> choice;
	cout << endl;
	return choice;
}


int chooseOnePage(System& system)
{
	int choice;
	system.printAllSystemPages();
	cout << "Enter the index of the fan page: ";
	cin >> choice;
	cout << endl;
	return choice;
}


void printAllFriendsOrFansEntity(System& system)
{
	int user_input;
	int index;
	cout << "Do you want to choose from members or from fan pages?" << endl << "Enter 1 for members, or 2 for fan pages: ";
	cin >> user_input;
	switch (user_input)
	{
	case 1:
		index = chooseOneMember(system);
		cout << endl;
		system.printMemberName(index - 1);
		cout << "'s friends are:" << endl;
		system.printAllFriendsOfMember(index - 1);
		break;
	case 2:
		index = chooseOnePage(system);
		cout << endl;
		system.printPageName(index -1);
		cout << "'s fans are:" << endl;
		system.printAllFandsOfPage(index - 1);
		break;
	default:
		break;
	}
}



void unlinkFanFromPage(Member& mem, Fan_page& page)
{
	mem.removePage(page);
	//page.removeFan(mem);
}


void addNewStatusToFanPageOrMember(System& system)
{
	int choice, index;
	Status* newStatus;

	cout << "enter 1 to add new status for a member" << endl;
	cout << "enter 2 to add new status for a fan page" << endl;
	cout << "please enter your choice here:  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "choose a user to which you want to add a new status: " << endl;
		index = chooseOneMember(system);
		newStatus = createNewStatus();
		system.addNewStatusToMember(newStatus, index - 1);
		break;
	case 2:
		cout << "choose a page to which you want to add a new status: " << endl;
		index = chooseOnePage(system);
		newStatus = createNewStatus();
		system.addNewStatusToFanPage(newStatus, index - 1);
		break;

	default:
		break;
	}
}


void showAllStatusesOfAFanPageOrMember(System& system)
{
	int choice, index;

	cout << "enter 1 to choose a member" << endl;
	cout << "enter 2 to choose a fan page" << endl;
	cout << "please enter your choice here:  ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "choose a user to see their statuses " << endl;
		index = chooseOneMember(system);
		system.showAllStatusesOfAMember(index - 1);
		break;
	case 2:
		cout << "choose a page to see its statuses: " << endl;
		index = chooseOnePage(system);
		system.showAllStatusesOfAFanPage(index - 1);
		break;

	default:
		break;
	}
}


void ShowTenStatusesOfEachFriend(System& system)
{
	int index;
	cout << "choose a member by entering their index number: " << endl;
	index = chooseOneMember(system);
	system.ShowTenLatestStatusesOfEachFriend(index - 1);
}


void linkFriendshipInSystem(System& system)
{
	int index1, index2;

	cout << "choose the first friend by entering their index number: " << endl;
	index1 = chooseOneMember(system);
	cout << "choose the second friend by entering their index number: " << endl;
	index2 = chooseOneMember(system);
	system.linkFriends(index1 - 1, index2 - 1);
}


void unLinkFriendshipInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a user from which you want to unlink a friend: " << endl;
	index1 = chooseOneMember(system);
	cout << "choose the friend you want to unlink: " << endl;
	system.printAllFriendsOfMember(index1 - 1);
	cin >> index2;
	system.unLinkFriends(index1 - 1, index2 - 1);
}


void addFanToPageInSystem(System& system)
{
	int index1, index2;
	cout << "choose the fan page you want to add a member as a fan to : " << endl;
	index1 = chooseOnePage(system);
	cout << "choose the memeber you wish to add to a fan page: " << endl;
	index2 = chooseOneMember(system);
	system.addFanToAPage(index2 - 1, index1 - 1);
}


void removeFanFromPageInSystem(System& system)
{
	int index1, index2;
	Member* selected_friend;

	cout << "choose a fan page from which you want to unlink a fan: " << endl;
	index1 = chooseOnePage(system);
	cout << "choose the fan you want to unlink:  " << endl;
	system.printAllFandsOfPage(index1 - 1);
	cin >> index2;
	system.removeFanFromAFanPage(index1 - 1, index2 - 1);
}

void printMenu()
{
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

	case 1:
		addNewUserToSystem(system);
		break;

	case 2:
		addNewPageToSystem(system);
		break;

	case 3:
		addNewStatusToFanPageOrMember(system);
		break;

	case 4:
		showAllStatusesOfAFanPageOrMember(system);
		break;

	case 5:
		ShowTenStatusesOfEachFriend(system);
		break;

	case 6:
		linkFriendshipInSystem(system);
		break;

	case 7:
		unLinkFriendshipInSystem(system);
		break;

	case 8:
		addFanToPageInSystem(system);
		break;

	case 9:
		removeFanFromPageInSystem(system);
		break;

	case 10:
		printAllRegisteredEntitiesInSystem(system);
		break;

	case 11:
		printAllFriendsOrFansEntity(system);
		break;

	case 12:
		exit = true;
		cout << "good bye" << endl;
		break;

	default:
		break;
	}
	return exit;
}