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

#include "BeRestartWindow.h"
#include "constants.h"
#include <Box.h>
#include <StatusBar.h>
#include <String.h>
#include <stdlib.h>
#include <stdio.h>

BeRestartWindow::BeRestartWindow()
	: BWindow(BRect(100,100,500,170), "BeRestart", B_TITLED_WINDOW, B_NOT_ANCHORED_ON_ACTIVATE), shutdownIn(0), elapsedShutdown(0)
{
	BRect brBar = Bounds();
	brBar.top += 19;
	BBox *bvMainView = new BBox(brBar, "CoveringView", 
					   B_FOLLOW_ALL, 
					   B_NAVIGABLE|B_WILL_DRAW|B_DRAW_ON_CHILDREN,
					   B_NO_BORDER);
					   
	brBar = Bounds();
	brBar.InsetBy(5.0, 5.0);
	bsbStatus = new BStatusBar(brBar, "CoveringView");

	brBar = Bounds();
	brBar.bottom = brBar.top + 19;
	BeRestartMenuBar *brmbMenu = new BeRestartMenuBar(brBar);

	
	AddChild(bvMainView);
	bvMainView->AddChild(bsbStatus);
	AddChild(brmbMenu);
	bsbStatus->Reset("Status: ");
	bsbStatus->Update(0,"N/A");
	ShutdownWindow = new BeRestartShutdownWindow(this);
}

BeRestartWindow::~BeRestartWindow()
{
}

void BeRestartWindow::MessageReceived(BMessage *bmMessage)
{
	BString myString;
	switch(bmMessage->what)
	{
		case RESTART_TRACKER:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Tracker");
			system("kill -KILL Tracker");
			bsbStatus->Update(50,"Starting Traker");
			system("/boot/beos/system/Tracker &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_DESKBAR:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Deskbar");
			system("kill -KILL Deskbar");
			bsbStatus->Update(50,"Starting Deskbar");
			system("/boot/beos/system/Deskbar &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_MEDIA:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Media Server");
			system("kill -KILL  media_server media_addon_server");
			snooze(500000L);
			bsbStatus->Update(33,"Starting Media Server");
			system("/boot/beos/system/servers/media_server &");
			bsbStatus->Update(66,"Starting Media Addon Server");
			system("/boot/beos/system/servers/media_addon_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_PRINT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Print Server");
			system("kill -KILL print_server");
			bsbStatus->Update(50,"Starting Print Server");
			system("/boot/beos/system/servers/print_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_AUDIO:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Audio Server");
			system("kill -KILL audio_server");
			bsbStatus->Update(50,"Starting Audio Server");
			system("/boot/beos/system/servers/audio_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_NET:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Net Server");
			system("kill -KILL net_server");
			bsbStatus->Update(50,"Starting Net Server");
			system("/boot/beos/system/servers/net_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_MAIL:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Mail Daemon");
			system("kill -KILL mail_daemon");
			bsbStatus->Update(50,"Starting Mail Daemon");
			system("/boot/beos/system/servers/mail_daemon &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_DEBUG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Debug Server");
			system("kill -KILL debug_server");
			bsbStatus->Update(50,"Starting Debug Server");
			system("/boot/beos/system/servers/debug_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_INPUT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Input Server");
			system("kill -KILL input_server");
			bsbStatus->Update(50,"Starting Input Server");
			system("/boot/beos/system/servers/input_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_SYSLOG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Syslog Daemon");
			system("kill -KILL syslog_daemon");
			bsbStatus->Update(50,"Starting Syslog Daemon");
			system("/boot/beos/system/servers/syslog_daemon &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case RESTART_MIDI:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Midi Server");
			system("kill -KILL midi_server");
			bsbStatus->Update(50,"Starting Midi Server");
			system("/boot/beos/system/servers/midi_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
			
		case RESTART_ALL:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing All");
			system("kill -KILL Tracker Deskbar debug_server input_server syslog_daemon media_server media_addon_server print_server audio_server net_server mail_daemon");
			bsbStatus->Update(50,"Starting All");
			system("source /boot/beos/system/boot/Bootscript");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
			
		case KILL_TRACKER:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Tracker");
			system("kill -KILL Tracker");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_DESKBAR:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Deskbar");
			system("kill -KILL Deskbar");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_MEDIA:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Media Server");
			system("kill -KILL  media_server media_addon_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_PRINT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Print Server");
			system("kill -KILL print_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_AUDIO:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Audio Server");
			system("kill -KILL audio_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_NET:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Net Server");
			system("kill -KILL net_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_MAIL:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Mail Daemon");
			system("kill -KILL mail_daemon");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_DEBUG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Debug Server");
			system("kill -KILL debug_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_INPUT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Input Server");
			system("kill -KILL input_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_SYSLOG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Syslog Daemon");
			system("kill -KILL syslog_daemon");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case KILL_MIDI:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Killing Midi Server");
			system("kill -KILL midi_server");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;

		case START_TRACKER:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Traker");
			system("/boot/beos/system/Tracker &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_DESKBAR:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Deskbar");
			system("/boot/beos/system/Deskbar &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_MEDIA:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Media Server");
			system("/boot/beos/system/servers/media_server &");
			bsbStatus->Update(50,"Starting Media Addon Server");
			system("/boot/beos/system/servers/media_addon_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_PRINT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Print Server");
			system("/boot/beos/system/servers/print_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_AUDIO:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Audio Server");
			system("/boot/beos/system/servers/audio_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_NET:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Net Server");
			system("/boot/beos/system/servers/net_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_MAIL:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Mail Daemon");
			system("/boot/beos/system/servers/mail_daemon &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_DEBUG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Debug Server");
			system("/boot/beos/system/servers/debug_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_INPUT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Input Server");
			system("/boot/beos/system/servers/input_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_SYSLOG:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Syslog Daemon");
			system("/boot/beos/system/servers/syslog_daemon &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;
		case START_MIDI:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Starting Midi Server");
			system("/boot/beos/system/servers/midi_server &");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;			
		
		case BR_REBOOT:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Rebooting");
			system("/bin/shutdown -r");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;			
		case BR_SHUTDOWN:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0,"Shutdown");
			system("/bin/shutdown");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			break;			
		case BR_SHUTDOWN_1M:
			shutdownIn = 60;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_2M:
			shutdownIn = 120;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_5M:
			shutdownIn = 300;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_15M:
			shutdownIn = 900;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_30M:
			shutdownIn = 1800;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_1H:
			shutdownIn = 3600;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_2H:
			shutdownIn = 7200;
			StartShutdown();
			break;			
		case BR_SHUTDOWN_5H:
			shutdownIn = 18000;
			StartShutdown();
			break;			
		case BR_START_SHUTDOWN:
			if(bmMessage->FindString("brShutdownTime", &myString) == B_OK)
			{
				shutdownIn = atoi(myString.String());
				StartShutdown();
			} else {
				bsbStatus->Update(100, "Error");
			}
			break;
		case SHOW_SHUTDOWN:
			while(ShutdownWindow->IsHidden())
				ShutdownWindow->Show();
			ShutdownWindow->Minimize(false);
			break;
		case CANCEL_SHUTDOWN:
			bsbStatus->Reset("Status: ");
			bsbStatus->Update(0, "Cancel Shutdown");
			system("kill shutdown");
			bsbStatus->Update(100, "Done");
			SetTitle("BeRestart");
			be_app->SetPulseRate(0);
			shutdownIn = 0;
			elapsedShutdown = 0;
			break;
		case B_ABOUT_REQUESTED:
			be_app->PostMessage(B_ABOUT_REQUESTED);
			break;
		default:
			BWindow::MessageReceived(bmMessage);
			break;
	}
}

bool BeRestartWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

void BeRestartWindow::StartShutdown()
{
	if(!shutdownIn)
		return;	
	system("kill shutdown");
	elapsedShutdown = 0;
	BString shutdownExec;
	shutdownExec << "/bin/shutdown -d " << shutdownIn << " &";
	system(shutdownExec.String());
	bsbStatus->Reset("Status: ");
	
	shutdownExec = "Shutting down in ";
	shutdownExec << (shutdownIn - elapsedShutdown) / 60 << " minute(s) and " << (shutdownIn - elapsedShutdown) % 60 << " second(s)";
	
	bsbStatus->Update(0, shutdownExec.String());
	SetTitle("BeRestart");

	be_app->SetPulseRate(PULSE_SPEED * 1000000);
}

void BeRestartWindow::ShutdownPulse()
{
	if(!shutdownIn)
	{
		be_app->SetPulseRate(0);
		return;
	}
	elapsedShutdown += PULSE_SPEED;
	BString shutdownExec;
	shutdownExec << "Shutting down in " << (shutdownIn - elapsedShutdown) / 60 << " minute(s) and " << (shutdownIn - elapsedShutdown) % 60 << " second(s)";

	Lock();
	bsbStatus->Update(((float) elapsedShutdown / shutdownIn ) * 100 - bsbStatus->CurrentValue(), shutdownExec.String());
	Unlock();
}