#include "stdafx.h"
#include "Logger.h"

#include <fstream>

using namespace std;

CLogger::CLogger()
{
}


CLogger::~CLogger()
{
}


void CLogger::log(CString str)
{
	ofstream ofs;
	ofs.open("log.txt", std::ofstream::out | std::ofstream::app);
	ofs << CT2A(str) << endl;
	ofs.close();
}