#include "status.h"
using namespace std;


Status::Status(string text, string time) noexcept(false)
{
	if (text.size() == EMPTY)
		throw EmptyTextException();
	if (time.size() == EMPTY)
		throw EmptyTimeException();
	this->text = text;
	this->time = time;
}

Status::Status(const Status& other)
{
	text = other.text;
	time = other.time;
}


/*
void Status::showStatus() const
{
	cout << text << endl;
	cout <<"Status publish time: " << time << endl;
}
*/

ostream& operator<<(ostream& os, const Status& status)
{
	os << status.text << endl;
	status.attached(os);
	os << "Status publish time: " << status.time << endl;
	return os;
}



bool Status::operator==(const Status& status) const
{
	bool res=false;
	if (text == status.text)
		res = true;
	return res;  
}

bool Status::operator!=(const Status& status) const
{
	return !(*this == status);
}
