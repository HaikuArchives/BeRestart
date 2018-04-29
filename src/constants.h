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

#ifndef BERESTART_CONSTANTS_H
#define BERESTART_CONSTANTS_H

const uint32 RESTART_TRACKER	= 'brRT';
const uint32 RESTART_DESKBAR	= 'brRD';
const uint32 RESTART_MEDIA		= 'brRM';
const uint32 RESTART_PRINT		= 'brRP';
const uint32 RESTART_AUDIO		= 'brRA';
const uint32 RESTART_NET		= 'brRN';
const uint32 RESTART_MAIL		= 'brRS';
const uint32 RESTART_DEBUG		= 'brRE';
const uint32 RESTART_INPUT		= 'brRI';
const uint32 RESTART_SYSLOG		= 'brRY';
const uint32 RESTART_MIDI		= 'brRZ';
const uint32 RESTART_ALL		= 'brRL';

const uint32 KILL_TRACKER		= 'brKT';
const uint32 KILL_DESKBAR		= 'brKD';
const uint32 KILL_MEDIA			= 'brKM';
const uint32 KILL_PRINT			= 'brKP';
const uint32 KILL_AUDIO			= 'brKA';
const uint32 KILL_NET			= 'brKN';
const uint32 KILL_MAIL			= 'brKS';
const uint32 KILL_DEBUG			= 'brKE';
const uint32 KILL_INPUT			= 'brKI';
const uint32 KILL_SYSLOG		= 'brKY';
const uint32 KILL_MIDI			= 'brKZ';

const uint32 START_TRACKER		= 'brST';
const uint32 START_DESKBAR		= 'brSD';
const uint32 START_MEDIA		= 'brSM';
const uint32 START_PRINT		= 'brSP';
const uint32 START_AUDIO		= 'brSA';
const uint32 START_NET			= 'brSN';
const uint32 START_MAIL			= 'brSS';
const uint32 START_DEBUG		= 'brSE';
const uint32 START_INPUT		= 'brSI';
const uint32 START_SYSLOG		= 'brSY';
const uint32 START_MIDI			= 'brSZ';

const uint32 BR_REBOOT			= 'brTR';
const uint32 BR_SHUTDOWN		= 'brTS';
const uint32 BR_SHUTDOWN_1M		= 'brT1';
const uint32 BR_SHUTDOWN_2M		= 'brT2';
const uint32 BR_SHUTDOWN_5M		= 'brT3';
const uint32 BR_SHUTDOWN_15M	= 'brT4';
const uint32 BR_SHUTDOWN_30M	= 'brT5';
const uint32 BR_SHUTDOWN_1H		= 'brT6';
const uint32 BR_SHUTDOWN_2H		= 'brT7';
const uint32 BR_SHUTDOWN_5H		= 'brT8';
const uint32 BR_START_SHUTDOWN	= 'brTN';

const uint32 SHOW_SHUTDOWN		= 'brTO';
const uint32 CANCEL_SHUTDOWN	= 'brTC';
#endif