#include "FileLocker.h"
#include <sys/file.h>
#include <iostream>
#include <unistd.h>

FileLocker::FileLocker(std::string file) : file(file) {
	this->fileDesc = open(file.c_str(), O_RDWR | O_CREAT);
	std::cout << "fileDesc: " << this->fileDesc << std::endl;
	this->locked = flock(this->fileDesc, LOCK_EX | LOCK_NB);
	std::cout << "locked: " << this->locked << std::endl;
	if (this->locked == 0) {
		std::cout << "File '" << file << "' was locked" << std::endl;
	} else {
		std::cout << "File '" << file << "' was NOT locked" << std::endl;
		close(this->fileDesc);
	}
}

FileLocker::~FileLocker() {
	int unlocked = flock(this->fileDesc, LOCK_UN);
	if (unlocked == 0) {
		std::cout << "File '" << file << "' was unlocked" << std::endl;
		close(this->fileDesc);
	} else {
		std::cout << "File '" << file << "' was NOT unlocked" << std::endl;
	}
}

int FileLocker::isLocked() {
	return locked;
}
