#include "status_video.h"
using namespace std;



StatusVideo::StatusVideo(const string text,const string time,const string video) : Status(text, time)
{
	if (video.size() == EMPTY)
		throw EmptyVideoException();
	this->video = video;
}


StatusVideo::StatusVideo(const StatusVideo& other) : Status(other)
{
	this->video = other.video;
}


void StatusVideo::attached(std::ostream& os) const
{
	if (typeid(os) == typeid(ofstream))
	{
		os << video << endl;
	}
	else
	{
		string command = "start " + video;
		system(command.c_str());
	}
}


bool StatusVideo::operator==(const Status& other)  const
{
	if (!Status::operator==(other))
		return false;

	const StatusVideo* temp = dynamic_cast<const StatusVideo*>(&other);
	if (temp == NULL)
		return false;

	return video == temp->video;

}


bool StatusVideo::operator!=(const Status& other) const
{
	return !((*this) == other);
}


Status* StatusVideo::clone() const
{
	return new StatusVideo(*this);
}