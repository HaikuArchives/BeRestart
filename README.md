BeRestart v4.0 by Brad Froehle (EnochRoot)
--------------------------------------------------------------------------

released under the GPL (http://www.gnu.org)

Install:
Drag into the folder specified
Look for it in the BeOS Menu -> Applications -> BeRestart


Usage:
GUI: Run the program, look at the menus.


Command line:
run BeRestart -help 
./BeRestart [-kill <name>] [-start <name>] [-restart <name>]
     [-reboot] [-shutdown <time>] [-hide] [-minimize] [-help]

Where <name> is Tracker, Deskbar, Media, Print, Audio, Net,
Mail, Debug, Input, Syslog, Midi or All

Where <time> is Now, 1M, 2M, 5M, 15M, 30M, 1H, 2H, and 5H
or use /bin/shutdown -d <time in minutes>


Also: Scripts! 
set the script file type text/x-BeRestart-script
then when they are opened, BeRestart will startup and parse the contents of the file as if they were passed on the command line,

see in the scripts folder for more details


Shutdown functions now tell you how long until the shutdown takes place.


An about Box was added!, and shutdown problems were fixed.

-minimize
minimizes the program after launch

-hide
minimizes the program, but will close the program after the remaining
command line arguments are done

--------------------------------------------------------------------------
based on works by evilcthul aka Lambert Kiang

