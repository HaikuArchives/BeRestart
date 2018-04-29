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

#include "BeRestartMenuBar.h"

BeRestartMenuBar::BeRestartMenuBar(BRect brMenuFrame)
	: BMenuBar(brMenuFrame, "BeRestartMenu", B_FOLLOW_LEFT_RIGHT | B_FOLLOW_TOP, B_ITEMS_IN_ROW, true)
{
	BMenu *bmShutdown = new BMenu("Shutdown...");
	bmShutdown->AddItem(new BMenuItem("Now", new BMessage(BR_SHUTDOWN)));
	bmShutdown->AddSeparatorItem();
	bmShutdown->AddItem(new BMenuItem("1 Minute", new BMessage(BR_SHUTDOWN_1M)));
	bmShutdown->AddItem(new BMenuItem("2 Minutes", new BMessage(BR_SHUTDOWN_2M)));
	bmShutdown->AddItem(new BMenuItem("5 Minutes", new BMessage(BR_SHUTDOWN_5M)));
	bmShutdown->AddItem(new BMenuItem("15 Minutes", new BMessage(BR_SHUTDOWN_15M)));
	bmShutdown->AddItem(new BMenuItem("30 Minutes", new BMessage(BR_SHUTDOWN_30M)));
	bmShutdown->AddItem(new BMenuItem("1 Hour", new BMessage(BR_SHUTDOWN_1H)));
	bmShutdown->AddItem(new BMenuItem("2 Hours", new BMessage(BR_SHUTDOWN_2H)));
	bmShutdown->AddItem(new BMenuItem("5 Hours", new BMessage(BR_SHUTDOWN_5H)));
	bmShutdown->AddSeparatorItem();
	bmShutdown->AddItem(new BMenuItem("Custom...", new BMessage(SHOW_SHUTDOWN)));
	bmShutdown->AddSeparatorItem();
	bmShutdown->AddItem(new BMenuItem("Cancel", new BMessage(CANCEL_SHUTDOWN)));
	

	BMenu *bmFile = new BMenu("File");
	bmFile->AddItem(new BMenuItem("Reboot (soft)", new BMessage(RESTART_ALL)));
	bmFile->AddItem(new BMenuItem("Reboot (full)", new BMessage(BR_REBOOT)));
	bmFile->AddItem(bmShutdown);
	bmFile->AddSeparatorItem();
	bmFile->AddItem(new BMenuItem("About BeRestart...", new BMessage(B_ABOUT_REQUESTED), 'A'));
	bmFile->AddSeparatorItem();
	bmFile->AddItem(new BMenuItem("Quit", new BMessage(B_QUIT_REQUESTED), 'Q'));
	AddItem(bmFile);
	
	BMenu *bmRestart = new BMenu("Restart");
	bmRestart->AddItem(new BMenuItem("Tracker", new BMessage(RESTART_TRACKER)));
	bmRestart->AddItem(new BMenuItem("Deskbar", new BMessage(RESTART_DESKBAR)));
	bmRestart->AddItem(new BMenuItem("Media Services", new BMessage(RESTART_MEDIA)));
	bmRestart->AddItem(new BMenuItem("Print Server", new BMessage(RESTART_PRINT)));
	bmRestart->AddItem(new BMenuItem("Audio Server", new BMessage(RESTART_AUDIO)));
	bmRestart->AddItem(new BMenuItem("Net Server", new BMessage(RESTART_NET)));
	bmRestart->AddItem(new BMenuItem("Mail Daemon", new BMessage(RESTART_MAIL)));
	bmRestart->AddItem(new BMenuItem("Debug Daemon", new BMessage(RESTART_DEBUG)));
	bmRestart->AddItem(new BMenuItem("Input Daemon", new BMessage(RESTART_INPUT)));
	bmRestart->AddItem(new BMenuItem("Syslog Daemon", new BMessage(RESTART_SYSLOG)));
	bmRestart->AddItem(new BMenuItem("Midi Server", new BMessage(RESTART_MIDI)));
	bmRestart->AddSeparatorItem();
	bmRestart->AddItem(new BMenuItem("All", new BMessage(RESTART_ALL)));
	AddItem(bmRestart);
	
	BMenu *bmKill = new BMenu("Kill");
	bmKill->AddItem(new BMenuItem("Tracker", new BMessage(KILL_TRACKER)));
	bmKill->AddItem(new BMenuItem("Deskbar", new BMessage(KILL_DESKBAR)));
	bmKill->AddItem(new BMenuItem("Media Services", new BMessage(KILL_MEDIA)));
	bmKill->AddItem(new BMenuItem("Print Server", new BMessage(KILL_PRINT)));
	bmKill->AddItem(new BMenuItem("Audio Server", new BMessage(KILL_AUDIO)));
	bmKill->AddItem(new BMenuItem("Net Server", new BMessage(KILL_NET)));
	bmKill->AddItem(new BMenuItem("Mail Daemon", new BMessage(KILL_MAIL)));
	bmKill->AddItem(new BMenuItem("Debug Daemon", new BMessage(KILL_DEBUG)));
	bmKill->AddItem(new BMenuItem("Input Daemon", new BMessage(KILL_INPUT)));
	bmKill->AddItem(new BMenuItem("Syslog Daemon", new BMessage(KILL_SYSLOG)));
	bmKill->AddItem(new BMenuItem("Midi Server", new BMessage(KILL_MIDI)));	
	AddItem(bmKill);

	BMenu *bmStart = new BMenu("Start");
	bmStart->AddItem(new BMenuItem("Tracker", new BMessage(START_TRACKER)));
	bmStart->AddItem(new BMenuItem("Deskbar", new BMessage(START_DESKBAR)));
	bmStart->AddItem(new BMenuItem("Media Services", new BMessage(START_MEDIA)));
	bmStart->AddItem(new BMenuItem("Print Server", new BMessage(START_PRINT)));
	bmStart->AddItem(new BMenuItem("Audio Server", new BMessage(START_AUDIO)));
	bmStart->AddItem(new BMenuItem("Net Server", new BMessage(START_NET)));
	bmStart->AddItem(new BMenuItem("Mail Daemon", new BMessage(START_MAIL)));
	bmStart->AddItem(new BMenuItem("Debug Daemon", new BMessage(START_DEBUG)));
	bmStart->AddItem(new BMenuItem("Input Daemon", new BMessage(START_INPUT)));
	bmStart->AddItem(new BMenuItem("Syslog Daemon", new BMessage(START_SYSLOG)));
	bmStart->AddItem(new BMenuItem("Midi Server", new BMessage(START_MIDI)));
	AddItem(bmStart);
}
