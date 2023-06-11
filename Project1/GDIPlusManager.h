#pragma once
#define FULL_WINTARD

#include "ChiliWin.h"

class GDIPlusManager {
public:
	GDIPlusManager();
	~GDIPlusManager();
private:
	static ULONG_PTR token;
	static int refCount;

};
