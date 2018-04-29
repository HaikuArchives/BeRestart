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

#include "BeRestart.h"
#include <SupportDefs.h>
#include <Entry.h>
#include <Path.h>
#include <File.h>
#include <String.h>
#include <Box.h>
#include <TextView.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool BeRestart::dontQuit = false;

int main()
{
	BeRestart *app = new BeRestart();
	app->Run();
	delete app;
}

BeRestart::BeRestart()
	: BApplication("application/x-vnd.EnochRoot-BeRestart")
{
	win = new BeRestartWindow();
	win->Show();
}

BeRestart::~BeRestart()
{

}

void BeRestart::MessageReceived(BMessage *bmMessage)
{
	switch(bmMessage->what)
	{
		default:
			BApplication::MessageReceived(bmMessage);
			break;
	}
}

void BeRestart::RefsReceived(BMessage *message)
{
	dontQuit = true;
	int i = 0;
	entry_ref myRef;
	while(message->FindRef("refs", i, &myRef) == B_OK)
	{
		i++;
		BEntry myEntry(&myRef);
		BPath myPath(&myEntry);
		FILE *in = fopen(myPath.Path(), "r");

		fseek(in, 0, SEEK_END);
		long size = ftell(in);
		fseek(in, 0, SEEK_SET);

		char word[size];

		int argc = 1;
		while(fscanf(in, "%s", word) != EOF)
		{
			argc++;
			printf("%s\n", word);
		}
		
		fseek(in, 0, SEEK_SET);
		char *argv[argc];
		argv[0] = strdup("BeRestart");
		for(int i = 1; i < argc; i++)
		{
			fscanf(in, "%s", word);
			argv[i] = strdup(word);
		}
		ArgvReceived(argc, argv);
		for(int i = 0; i < argc; i++)
			free(argv[i]);

	}
}


void BeRestart::ArgvReceived(int32 argc, char **argv)
{
	if(!dontQuit)
		win->Minimize(1);
	bool showhelp = false;
	if(argc == 1)
		showhelp = true;
	int i = 1;
	bool send = true;
	BMessage *myMessage = NULL;
	while(i < argc)
	{
		send = true;
		if(strcmp(argv[i], "-help") == 0)
		{
			showhelp = true;
		} 
		if(strcmp(argv[i], "-minimize") == 0)
		{
			dontQuit = true;
			win->Minimize(true);
		}
		if(strcmp(argv[i], "-hide") == 0)
		{
			win->Minimize(true);
		}
		else if(strcmp(argv[i], "-kill") == 0 && i + 1 < argc)
		{
			i++;
			if(strcmp(argv[i], "Tracker") == 0)
				myMessage = new BMessage(KILL_TRACKER);
			else if(strcmp(argv[i], "Deskbar") == 0)
				myMessage = new BMessage(KILL_DESKBAR);
			else if(strcmp(argv[i], "Media") == 0)
				myMessage = new BMessage(KILL_MEDIA);
			else if(strcmp(argv[i], "Print") == 0)
				myMessage = new BMessage(KILL_PRINT);
			else if(strcmp(argv[i], "Audio") == 0)
				myMessage = new BMessage(KILL_AUDIO);
			else if(strcmp(argv[i], "Net") == 0)
				myMessage = new BMessage(KILL_NET);
			else if(strcmp(argv[i], "Mail") == 0)
				myMessage = new BMessage(KILL_MAIL);
			else if(strcmp(argv[i], "Debug") == 0)
				myMessage = new BMessage(KILL_DEBUG);
			else if(strcmp(argv[i], "Input") == 0)
				myMessage = new BMessage(KILL_INPUT);
			else if(strcmp(argv[i], "Syslog") == 0)
				myMessage = new BMessage(KILL_SYSLOG);
			else if(strcmp(argv[i], "Midi") == 0)
				myMessage = new BMessage(KILL_MIDI);
			else 
				send = false;
			if(send)
				win->PostMessage(myMessage);
		}
		else if(strcmp(argv[i], "-start") == 0 && i + 1 < argc)
		{
			i++;
			if(strcmp(argv[i], "Tracker") == 0)
				myMessage = new BMessage(START_TRACKER);
			else if(strcmp(argv[i], "Deskbar") == 0)
				myMessage = new BMessage(START_DESKBAR);
			else if(strcmp(argv[i], "Media") == 0)
				myMessage = new BMessage(START_MEDIA);
			else if(strcmp(argv[i], "Print") == 0)
				myMessage = new BMessage(START_PRINT);
			else if(strcmp(argv[i], "Audio") == 0)
				myMessage = new BMessage(START_AUDIO);
			else if(strcmp(argv[i], "Net") == 0)
				myMessage = new BMessage(START_NET);
			else if(strcmp(argv[i], "Mail") == 0)
				myMessage = new BMessage(START_MAIL);
			else if(strcmp(argv[i], "Debug") == 0)
				myMessage = new BMessage(START_DEBUG);
			else if(strcmp(argv[i], "Input") == 0)
				myMessage = new BMessage(START_INPUT);
			else if(strcmp(argv[i], "Syslog") == 0)
				myMessage = new BMessage(START_SYSLOG);
			else if(strcmp(argv[i], "Midi") == 0)
				myMessage = new BMessage(START_MIDI);
			else 
				send = false;
			if(send)
				win->PostMessage(myMessage);
		}
		else if(strcmp(argv[i], "-restart") == 0 && i + 1 < argc)
		{
			i++;
			if(strcmp(argv[i], "Tracker") == 0)
				myMessage = new BMessage(RESTART_TRACKER);
			else if(strcmp(argv[i], "Deskbar") == 0)
				myMessage = new BMessage(RESTART_DESKBAR);
			else if(strcmp(argv[i], "Media") == 0)
				myMessage = new BMessage(RESTART_MEDIA);
			else if(strcmp(argv[i], "Print") == 0)
				myMessage = new BMessage(RESTART_PRINT);
			else if(strcmp(argv[i], "Audio") == 0)
				myMessage = new BMessage(RESTART_AUDIO);
			else if(strcmp(argv[i], "Net") == 0)
				myMessage = new BMessage(RESTART_NET);
			else if(strcmp(argv[i], "Mail") == 0)
				myMessage = new BMessage(RESTART_MAIL);
			else if(strcmp(argv[i], "Debug") == 0)
				myMessage = new BMessage(RESTART_DEBUG);
			else if(strcmp(argv[i], "Input") == 0)
				myMessage = new BMessage(RESTART_INPUT);
			else if(strcmp(argv[i], "Syslog") == 0)
				myMessage = new BMessage(RESTART_SYSLOG);
			else if(strcmp(argv[i], "Midi") == 0)
				myMessage = new BMessage(RESTART_MIDI);				
			else if(strcmp(argv[i], "All") == 0)
				myMessage = new BMessage(RESTART_ALL);
			else 
				send = false;
			if(send)
				win->PostMessage(myMessage);
		}
		else if(strcmp(argv[i], "-reboot") == 0 )
		{
			myMessage = new BMessage(BR_REBOOT);
			win->PostMessage(myMessage);
		}
		else if(strcmp(argv[i], "-shutdown") == 0  && i + 1 < argc)
		{
			i++;
			if(strcmp(argv[i], "Now") == 0)
				myMessage = new BMessage(BR_SHUTDOWN);
			else if(strcmp(argv[i], "1M") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_1M);
			else if(strcmp(argv[i], "2M") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_2M);
			else if(strcmp(argv[i], "5M") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_5M);
			else if(strcmp(argv[i], "15M") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_15M);
			else if(strcmp(argv[i], "30M") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_30M);
			else if(strcmp(argv[i], "1H") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_1H);
			else if(strcmp(argv[i], "2H") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_2H);
			else if(strcmp(argv[i], "5H") == 0)
				myMessage = new BMessage(BR_SHUTDOWN_5H);
			else 
				send = false;
			if(send)
				win->PostMessage(myMessage);
		}
		else
		{
		printf("unrecognized option %s\n", argv[i]);
			showhelp = true;
		}
		i++;
	}
	if(showhelp)
	{
	printf("Usage:\n");
	printf("%s [-kill <name>] [-start <name>] [-restart <name>]\n", argv[0]);
	printf("     [-reboot] [-shutdown <time>] [-help]\n\n");
	printf("Where <name> is Tracker, Deskbar, Media, Print, Audio, Net, ");
	printf("\nMail, Debug, Input, Syslog, Midi or All\n\n");
	printf("Where <time> is Now, 1M, 2M, 5M, 15M, 30M, 1H, 2H, and 5H\n");
	printf("or use /bin/shutdown -d <time in minutes>\n");
	}
	if(!dontQuit)
		be_app->PostMessage(B_QUIT_REQUESTED);
}

void BeRestart::Pulse()
{
	win->ShutdownPulse();
}

void BeRestart::AboutRequested()
{
	BRect location;
	if(win)
		location = win->Frame();
	else
		location.Set(70,70,270,170);
	location.OffsetBy(30,30);
	location.SetRightBottom(location.LeftTop()+ BPoint(200,100));
	
	const char* creditstext = 	"\nBeRestart Version " BERESTART_VERSION_TEXT "\n"
								"By Brad Froehle (EnochRoot)\n\n"
								"All comments/criticism/flames can be\n"
								"Directed to bradley_f@hotmail.com\n";

	BWindow *aboutWindow = new BWindow(location, "About BeRestart", B_TITLED_WINDOW, B_NOT_RESIZABLE | B_NOT_MINIMIZABLE | B_ASYNCHRONOUS_CONTROLS);
	BBox *mainView = new BBox(aboutWindow->Bounds(), "CoveringView", B_FOLLOW_ALL, B_NAVIGABLE|B_WILL_DRAW|B_DRAW_ON_CHILDREN, B_NO_BORDER);
	
	BTextView *credits = new BTextView(aboutWindow->Bounds(), 
		"credits", aboutWindow->Bounds(), B_FOLLOW_ALL, B_WILL_DRAW); 
	
	credits->SetText(creditstext, strlen(creditstext));
	credits->MakeSelectable(false);
	credits->MakeEditable(false);
	credits->SetAlignment(B_ALIGN_CENTER);
	credits->SetViewColor(216,216,216);

	mainView->AddChild(credits);
	aboutWindow->AddChild(mainView);
	aboutWindow->Show();
}