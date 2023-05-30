#pragma once
#include"Worker.h"

class boss :public Worker
{
public:
	boss(int id, string name, int dId);
	void Worker::showInfo();
	string Worker::getDeptName();
};