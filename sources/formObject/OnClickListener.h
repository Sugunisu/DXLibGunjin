#ifndef _ONCLICKLISTENER_
#define _ONCLICKLISTENER_

#include "View.h"
#include "../input/Mouse.h"

class OnClickListener {
public:
	virtual ~OnClickListener(){}
	virtual void OnClick(View* view){}
};

#endif
