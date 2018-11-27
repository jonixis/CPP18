#ifndef FILE_LOCKER_H
#define FILE_LOCKER_H

#include <string>

class FileLocker {
private:
	std::string file;
	int fileDesc;
	int locked;
public:
	FileLocker(std::string file);
	~FileLocker();

	int isLocked();
};


#endif
