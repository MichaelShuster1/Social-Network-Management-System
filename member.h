#ifndef MEMBER_H
#define MEMBER_H
#include <vector>
#include <string>
using namespace std;
#include "status.h"

class Fan_page;

class Member
{

private:
	string name;
	Date birth_date;
	vector<Status*> statuses;
	vector<Fan_page*> pages;
	vector<Member*> friends;

public:
	Member(const string _name,const Date& date)throw(const char*);
	Member(const Member& other);
	Member(Member&& other) noexcept(true);
	~Member();
	void operator+=(Member& _member); //adds a user to the members friends array
	void addStatus(Status& status);//adds a status to the members status array
	void addPage(Fan_page& page);//adds a fan page to the members fan pages array
	void removeFriend(Member& _member);//removes a user from the members friends array
	void removePage(Fan_page& page);//removes a page fom the users fan page array
	void showAllFriends() const ;//prints all friends of a member
	void showAllStatuses() const;//prints all statuses of a member
	void showName() const ;//prints members name
	void showTenRecentStatuses() const ;// prints the last 10 statuses of the member
	void showAllFriendsTenStatuses()const ;// prints 10 last statuses of each friend of the member
	Member* getMemberFromFriends(int i);//return the 'i' friend from the friends array
	const char* getName() const;// returns the members name
	int getFriendsSize() const;//return the friends array size
	int getPagesSize() const;//return the pages array size
	Fan_page* getPageFromPages(int i);//return the 'i' page from the pages array
	int getPageIndexFromPages(Fan_page& page) const;// return the index of the given page in the pages array of the member
	int getFriendIndexFromFriends(Member& member) const ;// return the index of the given member from the friends array of the member
	bool operator>(const Member& member) const;
};








#endif

