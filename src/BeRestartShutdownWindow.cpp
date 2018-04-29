/*  BeRestart - v2.0
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "BeRestartShutdownWindow.h"
#include "constants.h"
#include <math.h>
#include <Button.h>
#include <Box.h>
#include <stdlib.h>
#include <stdio.h>

BeRestartShutdownWindow::BeRestartShutdownWindow(BLooper *blLooper)
	: BWindow(BRect(200, 200, 585, 150), "Shutdown Time", B_TITLED_WINDOW, B_NOT_ANCHORED_ON_ACTIVATE | B_NOT_CLOSABLE)
{
	blMainWindow = blLooper;

	BRect brBar = Bounds();
	BBox *bvMainView = new BBox(brBar, "CoveringView", 
					   B_FOLLOW_ALL, 
					   B_NAVIGABLE|B_WILL_DRAW|B_DRAW_ON_CHILDREN,
					   B_NO_BORDER);

	//Init
	brBar = Bounds();
	brBar.InsetBy(5.0, 5.0);
	brBar.right -= 85 + 85;
	myText = new BTextControl(brBar, "shutdown_time", "Minutes until shutdown:   ", "", NULL);
	
	brBar = Bounds();
	brBar.left = brBar.right - 85;
	brBar.left -= 85;
	brBar.right -= 85;
	brBar.top +=5;
	brBar.bottom -= 5;
	BButton *button = new BButton(brBar, "shutdown_button", "Shutdown", new BMessage(BR_START_SHUTDOWN));

	brBar = Bounds();
	brBar.left = brBar.right - 85;
	brBar.top +=5;
	brBar.bottom -= 5;
	BButton *button2 = new BButton(brBar, "cancel_button", "Cancel", new BMessage(CANCEL_SHUTDOWN));


	AddChild(bvMainView);
	bvMainView->AddChild(myText);
	bvMainView->AddChild(button);
	bvMainView->AddChild(button2);
	Show();
	Hide();
}

BeRestartShutdownWindow::~BeRestartShutdownWindow()
{

}

void BeRestartShutdownWindow::MessageReceived(BMessage *msg)
{
	unsigned long myTime;
	switch(msg->what)
	{
		case BR_START_SHUTDOWN:
		{
			myTime = atol(myText->Text());
			myTime *= 60;
			char myString[(int) (log10(myTime)+2)];
			sprintf(myString, "%li", myTime);
			msg->AddString("brShutdownTime", myString);
			blMainWindow->PostMessage(msg);
			while(!IsHidden())
				Hide();
		}
			break;
		case CANCEL_SHUTDOWN:
			while(!IsHidden())
				Hide();
			break;
//		case SHOW_SHUTDOWN:
//			Show();
		default:
			BWindow::MessageReceived(msg);
			break;
	}

}