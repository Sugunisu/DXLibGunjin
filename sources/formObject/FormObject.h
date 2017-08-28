#ifndef _FORM_OBJECT_H_
#define _FORM_OBJECT_H_

#include "View.h"
#include "OnClickListener.h"

class FormObject : public View{
	protected:
		OnClickListener* mListener;
	public:
		virtual void SetOnClickListener(OnClickListener* listener){
			mListener = listener;
		}
};

#endif
