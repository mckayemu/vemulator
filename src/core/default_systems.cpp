/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-w7idth: 4 -*- */
/*
 * gelide
 * Copyright (C) 2008 - 2011 Juan Ángel Moreno Fernández
 *
 * gelide is free software.
 *
 * You can redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * gelide is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gelide.  If not, see <http://www.gnu.org/licenses/>
 */

#include "system_manager.hpp"

void CSystemManager::generateDefaultSystems(void){
	CSystem* l_system;
	CEmulator l_emulator;

	/*"id";"name";"description";"icon_file";"dat_file";"bios_file";"home_dir";"rom_dir";
"snap_dir";"tittle_dir";"front_dir";"back_dir";"media_dir";emulator_id;
"datname";"datDescription";"datcategory";"datversion";"datauthor";datgames;
*/

	/*
	 *  All - multiroms/multiemu sporte a todos los roms (cargar un directorio de multiples extensiones de roms)
	 *                           ESTO REQUIERE QUE BASADO EN LA EXTENSION SE PASE EL TIPO DE SISTEMA A EL EMULADOR
	 *                           ejemplo en el caso de mednafen no es necesario pero para xe/mess se necesita especificar
	 *                           ejemplo para xe se pasa -m y seguido de el nombre de la consola, habra que agregar 
	 *                           una nueva variable aparte de $gf como $ge (game extension) y una definicion que
	 *                           segun esta extension que se pasa dinamicamente, se determina que "palabra" de consola se pase al emulador.
	 */
	l_system = new CSystem();
	l_system->setName(_("All Roms"));
	l_system->setDescription(_("See al roms and run a multiemulator based on user criteria, end users recomended use specific system below."));
	l_system->setIconFile(GELIDE_PIXMAPS"xmame.png");
	l_system->setRomsDir("/var/emulation/roms/");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2");
	l_emulator.setParams(" -fs 0 -vdriver sdl -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" -keepaspect -skip_gameinfo -sound -multithreading -video sdl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams(" --lite --fullscreen --render 1 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess emula casi todos los sistemas
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);

	/*
	 *  Atari - 2600
	 */
	l_system = new CSystem();
	l_system->setName(_("Atari 2600"));
	l_system->setDescription(_("Originally known as the Atari VCS, was released in October 1977"));
	l_system->setIconFile(GELIDE_PIXMAPS"atari-2600.png");
	l_system->setRomsDir("/var/emulation/roms/atary");
	// Emulador Stella
	l_emulator.setId(0);
	l_emulator.setName(_("Stella"));
	l_emulator.setDescription(_("A multi-platform Atari VCS 2600 emulator"));
	l_emulator.setVersion("3.2.2");
	l_emulator.setAuthor(_("Bradford W. Mott & The Stella Team."));
	l_emulator.setHomepage("http://stella.sourceforge.net");
	l_emulator.setPath("/usr/bin/stella");
	l_emulator.setParams("-video gl -gl_fsmax 1 -gl_filter nearest -gl_aspect 1.7 -fullscreen 1 -center 1 -sound 1 -channels 2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"stella.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("a2600 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("a2600 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("a2600 -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Atari - 5200/7800
	 */
	l_system = new CSystem();
	l_system->setName(_("Atari 5200 y 7800"));
	l_system->setDescription(_("Atari 5200 SuperSystem replace 2600 and Atary 7800 was lasted released in 1986"));
	l_system->setIconFile(GELIDE_PIXMAPS"atari-7800.png");
	l_system->setRomsDir("/var/emulation/roms/atary");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" a7800 -keepaspect -skip_gameinfo -sound -multithreading -video sdl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" a5200 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" a5200 -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);


	/*
	 *  Atari - Jaguar
	 */
	l_system = new CSystem();
	l_system->setName(_("Atari Jaguar"));
	l_system->setDescription(_("The first 64-Bits gaming system released by Atari Corp. in 1993"));
	l_system->setIconFile(GELIDE_PIXMAPS"atari-jaguar.png");
	l_system->setRomsDir("/var/emulation/roms/vjr");
	// Emulador Virtual Jaguar Gcc/Sdl
	l_emulator.setId(0);
	l_emulator.setName(_("Virtual Jaguar"));
	l_emulator.setDescription(_("Jaguar emulator for linux ported from original"));
	l_emulator.setVersion("1.0.7");
	l_emulator.setAuthor(_("Niels Wagenaar, Carwin Jones, James L. Hammons and Adam Gree"));
	l_emulator.setHomepage("http://sdlemu.ngemu.com/");
	l_emulator.setPath("/usr/bin/virtualjaguar");
	l_emulator.setParams("\"$gf\" -window -nogl -bios ");
	l_emulator.setIconFile(GELIDE_PIXMAPS"virtualjaguar.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.138");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("jaguar -keepaspect -skip_gameinfo -sound -multithreading -video sdl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("jaguar -keepaspect -skip_gameinfo -sound -multithreading -video sdl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Atari - Lynx
	 */
	l_system = new CSystem();
	l_system->setName(_("Atari Lynx"));
	l_system->setDescription(_("Was a handheld game console released by Atari Corporation in 1989"));
	l_system->setIconFile(GELIDE_PIXMAPS"atari-lynx.png");
	l_system->setRomsDir("/var/emulation/roms/lnx");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -lynx.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2");
	l_emulator.setParams(" -lynx.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(2);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" lynx -keepaspect -skip_gameinfo -sound -multithreading -video sdl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);
	// Emulador handysdl
	l_emulator.setId(0);
	l_emulator.setName(_("Handy/SDL"));
	l_emulator.setDescription(_("SDL based port of the famous Handy Atari Lynx emulator"));
	l_emulator.setVersion("0.82 R1");
	l_emulator.setAuthor(_("Niels Wagenaar & Caz"));
	l_emulator.setHomepage("http://sdlemu.ngemu.com/handysdl.php");
	l_emulator.setPath("/usr/bin/sdlhandy");
	l_emulator.setParams("\"$gf\" -sound ");
	l_emulator.setIconFile(GELIDE_PIXMAPS"handysdl.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" lynx -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" lynx -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" lynx -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Bandai - WonderSwan
	 */
	l_system = new CSystem();
	l_system->setName(_("Bandai WonderSwan"));
	l_system->setDescription(_("Handheld 16-Bits game console released in Japan by Bandai in 1999"));
	l_system->setIconFile(GELIDE_PIXMAPS"bandai-wonderswan.png");
	l_system->setRomsDir("/var/emulation/roms/wsc");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -wswan.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2");
	l_emulator.setParams(" -wswan.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" wswan -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" wswan -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 -m wonderswan \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" wswan -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Bandai - WonderSwan Color
	 */
	l_system = new CSystem();
	l_system->setName(_("Bandai WonderSwan Color"));
	l_system->setDescription(_("WonderSwan color version released in Japan by Bandai in 2000"));
	l_system->setIconFile(GELIDE_PIXMAPS"bandai-wonderswancolor.png");
	l_system->setRomsDir("/var/emulation/roms/wsc");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -wswan.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2");
	l_emulator.setParams(" -wswan.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" wscolor -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" wscolor -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 -m wonderswan \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" wscolor -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Mame: Multiple Arcade Machine Emulator
	 */
	l_system = new CSystem();
	l_system->setName(_("Arcades"));
	l_system->setDescription(_("Multiple Arcade Machine Emulator"));
	l_system->setIconFile(GELIDE_PIXMAPS"arcade-mame.png");
	l_system->setRomsDir("/var/emulation/roms/mame");
	// Emulador SdlMame
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMame"));
	l_emulator.setDescription(_("Portable MAME version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert, R. Belmont and the MAME Team"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador XMame
	l_emulator.setId(0);
	l_emulator.setName(_("XMame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame Team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmame");
	l_emulator.setParams(" -vidmod 0 -ef 1 -aa -ka -rp \"$gp\" -skip_gameinfo \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador MAME
	l_emulator.setId(0);
	l_emulator.setName(_("Mame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("Nicola Salmoria and the Mame Team"));
	l_emulator.setHomepage("http://www.mamedev.org/");
	l_emulator.setPath("/usr/bin/mame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mame.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  NEC - Pc Engine
	 */
	l_system = new CSystem();
	l_system->setName(_("NEC Pc Engine"));
	l_system->setDescription(_("8-Bits video game console also known as TurboGrafx "));
	l_system->setIconFile(GELIDE_PIXMAPS"nec-pcengine.png");
	l_system->setRomsDir("/var/emulation/roms/pce");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -pce.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador Hu-Go
	l_emulator.setId(0);
	l_emulator.setName(_("Hu-Go!"));
	l_emulator.setDescription(_("Multiplatform Pc Engine / TurboGrafx emulator"));
	l_emulator.setVersion("2.12");
	l_emulator.setAuthor(_("Zeograd"));
	l_emulator.setHomepage("http://www.zeograd.com");
	l_emulator.setPath("/usr/bin/hugo");
	l_emulator.setParams(" -a -s \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"hu-go.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 con pce_fast debio lo pesado que es, mejor usar el mednaFEn 0.8 o hugo
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2");
	l_emulator.setParams(" -pce.stretch 0 -force_module pce_fast -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" tg16 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" tg16 -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" tg16 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  NEC - SuperGrafx
	 */
	l_system = new CSystem();
	l_system->setName(_("NEC SuperGrafx"));
	l_system->setDescription(_("8-Bits video game console successor of the Pc Engine"));
	l_system->setIconFile(GELIDE_PIXMAPS"nec-supergrafx.png");
	l_system->setRomsDir("/var/emulation/roms/pce");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -pce.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -pce.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador Hu-Go
	l_emulator.setId(0);
	l_emulator.setName(_("Hu-Go!"));
	l_emulator.setDescription(_("Multiplatform Pc Engine / TurboGrafx emulator"));
	l_emulator.setVersion("2.12");
	l_emulator.setAuthor(_("Zeograd"));
	l_emulator.setHomepage("http://www.zeograd.com");
	l_emulator.setPath("/usr/bin/hugo");
	l_emulator.setParams(" -a -s \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"hu-go.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" sgx -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" sgx -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - Famicom Disk System
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Famicom Disk System"));
	l_system->setDescription(_("Was released in 1986 by Nintendo as a peripheral for the Famicom console"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-famicom.png");
	l_system->setRomsDir("/var/emulation/roms/nes");
	// Emulador FCEUX
	l_emulator.setId(0);
	l_emulator.setName(_("FCEUX"));
	l_emulator.setDescription(_("A Evolution of the original FCE Ultra emulator"));
	l_emulator.setVersion("2.1.4a");
	l_emulator.setAuthor(_("The FCEUX team"));
	l_emulator.setHomepage("http://www.fceux.com");
	l_emulator.setPath("/usr/bin/fceux");
	l_emulator.setParams(" --autoscale 1 --keepratio 0 --opengl 0 --doublebuf 1 --fullscreen 0 --sound 1 --volume 50 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fceux.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -nes.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador FCEU
	l_emulator.setId(0);
	l_emulator.setName(_("FCEUltra"));
	l_emulator.setDescription(_("FCE Ultra best emulator for NES games"));
	l_emulator.setVersion("2.1.4a");
	l_emulator.setAuthor(_("The FCEUltra team"));
	l_emulator.setHomepage("http://fceultra.sourceforge.net/");
	l_emulator.setPath("/usr/bin/fceu");
	l_emulator.setParams(" -opengl 0 -doublebuf 1 -fs 0 -sound 1 -soundvol 50 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fceux.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -nes.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" famicom -keepaspect -skip_gameinfo -sound -multithreading -flop \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 -m famicom \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" famicom -keepaspect -skip_gameinfo -sound -multithreading -flop \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - Game Boy Color
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Game Boy y Color"));
	l_system->setDescription(_("Handheld portable that was released 1989, Game boy Color revitalised in October 1998"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-gameboycolor.png");
	l_system->setRomsDir("/var/emulation/roms/gbc");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -gb.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador VisualBoy Advance
	l_emulator.setId(0);
	l_emulator.setName(_("VisualBoy Advance"));
	l_emulator.setDescription(_("VBA is one of the most known emulators for Game Boy roms"));
	l_emulator.setVersion("1.8.0");
	l_emulator.setAuthor(_("Forgotten and The VBA Team."));
	l_emulator.setHomepage("http://vba.ngemu.com");
	l_emulator.setPath("/usr/bin/vba");
	l_emulator.setParams(" -2 --frameskip=2 --auto-frameskip --no-throttle -f 7 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"visualboyadvance.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -gb.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" gbcolor -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("gbcolor -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 -m gameboy \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("gbcolor -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - Game Boy Advance
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Game Boy Advance"));
	l_system->setDescription(_("32-Bit handheld video game console developed by Nintendo released in 2001"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-gameboyadvance.png");
	l_system->setRomsDir("/var/emulation/roms/gba");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -gba.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador VisualBoy Advance
	l_emulator.setId(0);
	l_emulator.setName(_("VisualBoy Advance"));
	l_emulator.setDescription(_("VBA is one of the most known emulators for Game Boy roms"));
	l_emulator.setVersion("1.8.0");
	l_emulator.setAuthor(_("Forgotten and The VBA Team."));
	l_emulator.setHomepage("http://vba.ngemu.com");
	l_emulator.setPath("/usr/bin/vba");
	l_emulator.setParams(" -2 --frameskip=3 --auto-frameskip --throttle=500 -f 0 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"visualboyadvance.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -gba.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" gba -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/bin/xe");
	l_emulator.setParams("--lite --render 1 -m gbadvance  \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" gba -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - NES
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Entertaiment System"));
	l_system->setDescription(_("8-Bit video game console developed by Nintendo and released in 1983"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-nes.png");
	l_system->setRomsDir("/var/emulation/roms/nes");
	// Emulador FCEUX
	l_emulator.setId(0);
	l_emulator.setName(_("FCEUX"));
	l_emulator.setDescription(_("A Evolution of the original FCE Ultra emulator"));
	l_emulator.setVersion("2.1.4a");
	l_emulator.setAuthor(_("The FCEUX team"));
	l_emulator.setHomepage("http://www.fceux.com");
	l_emulator.setPath("/usr/bin/fceux");
	l_emulator.setParams(" --autoscale 1 --keepratio 0 --opengl 0 --doublebuf 1 --fullscreen 0 --sound 1 --volume 50 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fceux.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -nes.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador FCEU
	l_emulator.setId(0);
	l_emulator.setName(_("FCEUltra"));
	l_emulator.setDescription(_("FCE Ultra best emulator for NES games"));
	l_emulator.setVersion("2.1.4a");
	l_emulator.setAuthor(_("The FCEUltra team"));
	l_emulator.setHomepage("http://fceultra.sourceforge.net/");
	l_emulator.setPath("/usr/bin/fceu");
	l_emulator.setParams(" -opengl 0 -doublebuf 1 -fs 0 -sound 1 -soundvol 50 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fceu.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -nes.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" nes -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" nes -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m famicom \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" nes -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - SNes
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Super Entertaiment System"));
	l_system->setDescription(_("16-Bits video game console sucessor of the Nes"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-snes.png");
	l_system->setRomsDir("/var/emulation/roms/snes");
	// Emulador Snes9x
	l_emulator.setId(0);
	l_emulator.setName(_("Snes9x"));
	l_emulator.setDescription(_("Snes9x Free Opensource SNes emulator"));
	l_emulator.setVersion("1.42");
	l_emulator.setAuthor(_("Gary Henderson / Jeremy Koot"));
	l_emulator.setHomepage("http://snes9x.com");
	l_emulator.setPath("/usr/bin/snes9x");
	l_emulator.setParams(" -ha -tr -hi -sc -16 -y 2 -i2 -windows -ne -r 6 -sq 6 -st -nc -sy -sy2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"snes9x.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -snes.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador Zsnes
	l_emulator.setId(0);
	l_emulator.setName(_("Zsnes"));
	l_emulator.setDescription(_("Zsnes - A Super Nintendo emulator"));
	l_emulator.setVersion("1.51");
	l_emulator.setAuthor(_("zsKnight & _Demo_"));
	l_emulator.setHomepage("http://www.zsnes.com");
	l_emulator.setPath("/usr/bin/zsnes");
	l_emulator.setParams(" -m -s -r 5 -k 75 -v 7 -ad sdl \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"zsnes.png");
	l_system->addEmulator(l_emulator);
	// Emulador Snes9x-Gtk
	l_emulator.setId(0);
	l_emulator.setName(_("Snes9x-gtk"));
	l_emulator.setDescription(_("Gtk+ port of Snes9x Free SNes emulator"));
	l_emulator.setVersion("1.52.79");
	l_emulator.setAuthor(_("Brandon Wright (bearoso)"));
	l_emulator.setHomepage("http://code.google.com/p/snes9x-gtk/");
	l_emulator.setPath("/usr/bin/snes9x-gtk");
	l_emulator.setParams("\"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"snes9x-gtk.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" snes -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" snes -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m superfamicom \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" snes -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - 64
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Ultra64"));
	l_system->setDescription(_("64-Bit console released by Nintendo in 1996 in Japan."));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-n64.png");
	l_system->setRomsDir("/var/emulation/roms/n64");
	// Emulador Mupen64plus 1.X series
	l_emulator.setId(0);
	l_emulator.setName(_("Mupen64Plus"));
	l_emulator.setDescription(_("Older Mupen64plus sucesor of the Mupen64 linux Nintendo 64 emulator"));
	l_emulator.setVersion("1.5");
	l_emulator.setAuthor(_("The Mupen64Plus Team"));
	l_emulator.setHomepage("http://code.google.com/p/mupen64plus");
	l_emulator.setPath("/usr/bin/mupen64plus");
	l_emulator.setParams("--nogui --noask --noosd --windowed --emumode 2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mupen64plus.png");
	l_system->addEmulator(l_emulator);
	// Emulador Mupen64plus 2.0 series
	l_emulator.setId(0);
	l_emulator.setName(_("Mupen64Plus 2"));
	l_emulator.setDescription(_("Evolution of the Mupen64plus for Nintendo 64 emulation modularity"));
	l_emulator.setVersion("1.99.5+");
	l_emulator.setAuthor(_("The Mupen64Plus Team"));
	l_emulator.setHomepage("https://github.com/mupen64plus");
	l_emulator.setPath("/usr/bin/mupen64plus2");
	l_emulator.setParams("--nogui --noask --noosd --windowed --emumode 2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mupen64plus.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" n64 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Mupen64 0.5 series
	l_emulator.setId(0);
	l_emulator.setName(_("Mupen64"));
	l_emulator.setDescription(_("Firts open source Nintendo 64 emulator"));
	l_emulator.setVersion("0.5");
	l_emulator.setAuthor(_("Hacktarux"));
	l_emulator.setHomepage("http://mupen64.emulation64.com");
	l_emulator.setPath("/usr/bin/mupen64_nogui");
	l_emulator.setParams(" --emumode 2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mupen64.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" n64 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - DS
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo DS y DS Lite"));
	l_system->setDescription(_("Dual-screen handheld console released by Nintendo in 2004"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-ds.png");
	l_system->setRomsDir("/var/emulation/roms/nds");
	// Emulador DesMume
	l_emulator.setId(0);
	l_emulator.setName(_("DeSmuME"));
	l_emulator.setDescription(_("A Nintendo DS emulator under GNU GPL"));
	l_emulator.setVersion("0.9.6");
	l_emulator.setAuthor(_("Yopyop and The DeSmuME team"));
	l_emulator.setHomepage("http://desmume.org/");
	l_emulator.setPath("/usr/bin/desmume-cli");
	l_emulator.setParams("--auto-pause --opengl-2d \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"desmume.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Nintendo - Virtualboy
	 */
	l_system = new CSystem();
	l_system->setName(_("Nintendo Virtual boy"));
	l_system->setDescription(_("Dual-screen handheld console released by Nintendo in 2004"));
	l_system->setIconFile(GELIDE_PIXMAPS"nintendo-vb.png");
	l_system->setRomsDir("/var/emulation/roms/nvb");
	// Emulador mednafen 0.9 emulates now Virtual Boy based in reality boy
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -vb.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SEGA - 32X
	 */
	l_system = new CSystem();
	l_system->setName(_("SEGA Mega drive y 32X"));
	l_system->setDescription(_("Add-on for the Mega Drive/Genesis who adds support for 32bits"));
	l_system->setIconFile(GELIDE_PIXMAPS"sega-32x.png");
	l_system->setRomsDir("/var/emulation/roms/smd");
	// Emulador gens
	l_emulator.setId(0);
	l_emulator.setName(_("Gens"));
	l_emulator.setDescription(_("Linux SEGA Mega Drive, 32X and SEGA CD emulator port of Gens"));
	l_emulator.setVersion("2.15.5");
	l_emulator.setAuthor(_("Stephane Akhoun"));
	l_emulator.setHomepage("http://gens.consolemul.com");
	l_emulator.setPath("/usr/bin/gens");
	l_emulator.setParams(" --window --soundrate 44100 --quickexit --render-mode 2 --disable-fps --enable-soundstereo --enable-sound \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"gens.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" 32x -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador gens
	l_emulator.setId(0);
	l_emulator.setName(_("Gens/GS"));
	l_emulator.setDescription(_("Evolution of Gens SEGA Mega Drive, 32X and SEGA CD emulator"));
	l_emulator.setVersion("2.16.7 (r7)");
	l_emulator.setAuthor(_("Stephane Dallongeville\nStephane Akhoun\nDavid Korth (GS)"));
	l_emulator.setHomepage("http://www.segaretro.org/Gens/GS");
	l_emulator.setPath("/usr/bin/gensgs");
	l_emulator.setParams(" --window --soundrate 44100 --quickexit --render-mode 2 --disable-fps --enable-soundstereo --enable-sound \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"gensgs.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -md.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" 32x -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SEGA - Game Gear
	 */
	l_system = new CSystem();
	l_system->setName(_("SEGA Game Gear"));
	l_system->setDescription(_("Handheld video games system released by SEGA as response to Game Boy"));
	l_system->setIconFile(GELIDE_PIXMAPS"sega-gamegear.png");
	l_system->setRomsDir("/var/emulation/roms/gg");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -gg.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador osmose
	l_emulator.setId(0);
	l_emulator.setName(_("Osmose"));
	l_emulator.setDescription(_("Open source SEGA Master System / Gamegear emulator"));
	l_emulator.setVersion("0.8");
	l_emulator.setAuthor(_("Bruno Vedder"));
	l_emulator.setHomepage("http://bcz.emu-france.com/osmose.htm");
	l_emulator.setPath("/usr/bin/osmose");
	l_emulator.setParams(" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"osmose.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -gg.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" gamegear -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" gamegear -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m gamegear \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" gamegear -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SEGA - Master System
	 */
	l_system = new CSystem();
	l_system->setName(_("SEGA Master System"));
	l_system->setDescription(_("8-Bits cartridge based video game console released by SEGA"));
	l_system->setIconFile(GELIDE_PIXMAPS"sega-mastersystem.png");
	l_system->setRomsDir("/var/emulation/roms/sms");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -sms.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -sms.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" sms -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador osmose
	l_emulator.setId(0);
	l_emulator.setName(_("Osmose"));
	l_emulator.setDescription(_("Open source SEGA Master System / Gamegear emulator"));
	l_emulator.setVersion("0.9.2");
	l_emulator.setAuthor(_("Bruno Vedder"));
	l_emulator.setHomepage("http://bcz.emu-france.com/osmose.htm");
	l_emulator.setPath("/usr/bin/osmose");
	l_emulator.setParams(" -bilinear \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"osmose.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" sms -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m mark3 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" sms -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SEGA - Mega Drive/Genesys
	 */
	l_system = new CSystem();
	l_system->setName(_("SEGA Genesys"));
	l_system->setDescription(_("16-Bits video game console developed by SEGA. Also known as Genesis"));
	l_system->setIconFile(GELIDE_PIXMAPS"sega-megadrive.png");
	l_system->setRomsDir("/var/emulation/roms/smd");
	// Emulador dgen
	l_emulator.setId(0);
	l_emulator.setName(_("Dgen"));
	l_emulator.setDescription(_("Open source SEGA Genesis with some Mega Drive capabilities"));
	l_emulator.setVersion("1.23");
	l_emulator.setAuthor(_("Joe Hess and Dave"));
	l_emulator.setHomepage("http://www.pknet.com/~joe/dgen-sdl.html");
	l_emulator.setPath("/usr/bin/dgen");
	l_emulator.setParams(" -S 2 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"dgen.png");
	l_system->addEmulator(l_emulator);
	// Emulador gens
	l_emulator.setId(0);
	l_emulator.setName(_("Gens"));
	l_emulator.setDescription(_("Linux SEGA Mega Drive, 32X and SEGA CD emulator port of Gens"));
	l_emulator.setVersion("2.15.5");
	l_emulator.setAuthor(_("Stephane Akhoun"));
	l_emulator.setHomepage("http://gens.consolemul.com");
	l_emulator.setPath("/usr/bin/gens");
	l_emulator.setParams(" --window --soundrate 44100 --quickexit --render-mode 2 --disable-fps --enable-soundstereo --enable-sound \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"gens.png");
	l_system->addEmulator(l_emulator);
	// Emulador gens
	l_emulator.setId(0);
	l_emulator.setName(_("Gens/GS"));
	l_emulator.setDescription(_("Evolution of Gens SEGA Mega Drive, 32X and SEGA CD emulator"));
	l_emulator.setVersion("2.16.7 (r7)");
	l_emulator.setAuthor(_("Stephane Dallongeville\nStephane Akhoun\nDavid Korth (GS)"));
	l_emulator.setHomepage("http://www.segaretro.org/Gens/GS");
	l_emulator.setPath("/usr/bin/gensgs");
	l_emulator.setParams(" --window --soundrate 44100 --quickexit --render-mode 2 --disable-fps --enable-soundstereo --enable-sound \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"gensgs.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -md.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" genesis -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" genesis -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m megadrive \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" genesis -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SEGA - SG1000
	 */
	l_system = new CSystem();
	l_system->setName(_("SEGA Mark SG1000"));
	l_system->setDescription(_("Was the first video game console developed by SEGA"));
	l_system->setIconFile(GELIDE_PIXMAPS"sega-sg1000.png");
	l_system->setRomsDir("/var/emulation/roms/sms");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -sms.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -sms.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" sg1000 -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" sg1000 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --render 1 -m sg1000 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" sg1000 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SNK - Neo Geo Pocket
	 */
	l_system = new CSystem();
	l_system->setName(_("SNK Neo Geo Pocket y Color"));
	l_system->setDescription(_("Handheld 16-bit video games system released by SNK, later released the color flavor."));
	l_system->setIconFile(GELIDE_PIXMAPS"snk-neogeopocketcolor.png");
	l_system->setRomsDir("/var/emulation/roms/ngp");
	// Emulador mednafen 0.8 es mas rapido al emula los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.8.D"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen");
	l_emulator.setParams(" -ngp.stretch 0 -fs 0 -vdriver sdl -sound 1 -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen.png");
	l_system->addEmulator(l_emulator);
	// Emulador mednafen 0.9 emula adicional snes/sega/psx y los mas importantes y conocidos hoy dia
	l_emulator.setId(0);
	l_emulator.setName(_("Mednafen 2"));
	l_emulator.setDescription(_("Portable Multi-system emulator under GPL"));
	l_emulator.setVersion("0.9.24"); // el ultimo emula 10 consolas, pero es mas lento, el 0.8.X emula solo 6 consolas
	l_emulator.setAuthor(_("The Mednafen team"));
	l_emulator.setHomepage("http://mednafen.sourceforge.net");
	l_emulator.setPath("/usr/bin/mednafen2"); // para supergrafx no usar pce_fast
	l_emulator.setParams(" -ngp.stretch 0 -fs 0 -vdriver sdl -sounddriver alsa -sounddevice sexyal-literal-default \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mednafen2.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" ngpc -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador Xe
	l_emulator.setId(0);
	l_emulator.setName(_("Xe Emulator"));
	l_emulator.setDescription(_("Freeware Multi-system emulator for Linux and Windows"));
	l_emulator.setVersion("2.16.2");
	l_emulator.setAuthor(_("James Li"));
	l_emulator.setHomepage("http://www.xe-emulator.com");
	l_emulator.setPath("/usr/local/bin/xe");
	l_emulator.setParams("--lite --fullscreen --render 1 -m neopocket \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xe.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" ngpc -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  SNK - Neo Geo AES
	 */
	l_system = new CSystem();
	l_system->setName(_("SNK Neo Geo Arcade Entertaiment System"));
	l_system->setDescription(_("Arcade cartridge-based video game system released in 1990 by SNK"));
	l_system->setIconFile(GELIDE_PIXMAPS"snk-neogeo.png");
	l_system->setRomsDir("/var/emulation/roms/ngp");
	// Emulador GnGeo
	l_emulator.setId(0);
	l_emulator.setName(_("GnGeo"));
	l_emulator.setDescription(_("A powerful and fast Neo Geo emulator for GNU/Linux"));
	l_emulator.setVersion("0.7");
	l_emulator.setAuthor(_("Mathieu Peponas & others"));
	l_emulator.setHomepage("http://gngeo.berlios.de/");
	l_emulator.setPath("/usr/bin/gngeo");
	l_emulator.setParams(" --no-fullscreen -H --system=home --scale=2 --sound \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"gngeo.png");
	l_system->addEmulator(l_emulator);
	// Emulador SdlMame
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMame"));
	l_emulator.setDescription(_("Portable MAME version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert, R. Belmont and the MAME Team"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador XMame
	l_emulator.setId(0);
	l_emulator.setName(_("XMame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame Team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmame");
	l_emulator.setParams("-vidmod 0 -ef 1 -aa -ka -rp \"$gp\" -skip_gameinfo \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador MAME
	l_emulator.setId(0);
	l_emulator.setName(_("Mame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("Nicola Salmoria and the Mame Team"));
	l_emulator.setHomepage("http://www.mamedev.org/");
	l_emulator.setPath("/usr/bin/mame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mame.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  ZiNc: 3d arcade emulator
	 */
	l_system = new CSystem();
	l_system->setName(_("ZiNc"));
	l_system->setDescription(_("Zinc - 3d arcade emulator"));
	l_system->setIconFile(GELIDE_PIXMAPS"arcade-zinc.png");
	l_system->setRomsDir("/var/emulation/roms/zinc");
	// Emulador ZiNc
	l_emulator.setId(0);
	l_emulator.setName(_("ZiNc"));
	l_emulator.setDescription(_("Emulator for Sony ZN-1 and ZN-2 and Namco System 11 hardware"));
	l_emulator.setVersion("1.1");
	l_emulator.setAuthor(_("The_Author and DynaChicken"));
	l_emulator.setHomepage("http://www.emuhype.com");
	l_emulator.setPath("/usr/bin/zinc");
	l_emulator.setParams("`$ef --list-games|awk '/\\\[$gn/ {print $1}'` --roms-directory=\"$gp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"zinc.png");
	l_system->addEmulator(l_emulator);
	// Emulador SdlMame
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMame"));
	l_emulator.setDescription(_("Portable MAME version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert, R. Belmont and the MAME Team"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador XMame
	l_emulator.setId(0);
	l_emulator.setName(_("XMame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame Team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmame");
	l_emulator.setParams(" -vidmod 0 -ef 1 -aa -ka -rp \"$gp\" -skip_gameinfo \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador MAME
	l_emulator.setId(0);
	l_emulator.setName(_("Mame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("Nicola Salmoria and the Mame Team"));
	l_emulator.setHomepage("http://www.mamedev.org/");
	l_emulator.setPath("/usr/bin/mame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mame.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Sinclair - ZX Spectrum
	 */
	l_system = new CSystem();
	l_system->setName(_("Sinclair ZX Spectrum"));
	l_system->setDescription(_("An 8-bit personal home computer released in 1982 by Sinclair Research Ltd"));
	l_system->setIconFile(GELIDE_PIXMAPS"sinclair-zxspectrum.png");
	l_system->setRomsDir("/var/emulation/roms/zxs");
	// Emulador fuse
	l_emulator.setId(0);
	l_emulator.setName(_("Fuse"));
	l_emulator.setDescription(_("The Free Unix Spectrum Emulator (Fuse)"));
	l_emulator.setVersion("1.0.0.1");
	l_emulator.setAuthor(_("Philip Kendall"));
	l_emulator.setHomepage("http://fuse-emulator.sourceforge.net");
	l_emulator.setPath("/usr/bin/fuse-sdl");
	l_emulator.setParams(" --kempston --graphics-filter tv2x \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fuse.png");
	l_system->addEmulator(l_emulator);	
	// Emulador spectemu
	l_emulator.setId(0);
	l_emulator.setName(_("SpectEmu"));
	l_emulator.setDescription(_("A 48k ZX-Spectrum emulator for Linux and other UNIX"));
	l_emulator.setVersion("0.94");
	l_emulator.setAuthor(_("Miklos Szeredi"));
	l_emulator.setHomepage("http://www.inf.bme.hu/~mszeredi/spectemu");
	l_emulator.setPath("/usr/bin/xspect");
	l_emulator.setParams(" -quick-load \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"spectemu.png");
	l_system->addEmulator(l_emulator);		
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess (Tapes)"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("spec128 -noreadconfig -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cass \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess (Tapes)"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("spec128 -noreadconfig -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cass \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador fbzx
	l_emulator.setId(0);
	l_emulator.setName(_("FBZX"));
	l_emulator.setDescription(_("A ZX Spectrum emulator for FrameBuffer"));
	l_emulator.setVersion("2.4.2");
	l_emulator.setAuthor(_("Raster Software Vigo (Sergio Costas)"));
	l_emulator.setHomepage("http://www.rastersoft.com/fbzx.html");
	l_emulator.setPath("/usr/bin/fbzx");
	l_emulator.setParams("-fs -db -ds \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fbzx.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess (Snaps)"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("spec128 -noreadconfig -keepaspect -skip_gameinfo -sound -multithreading -video opengl -dump \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess (Snaps)"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("spec128 -noreadconfig -keepaspect -skip_gameinfo -sound -multithreading -video opengl -dump \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Amstrad - GX4000
	 */
	l_system = new CSystem();
	l_system->setName(_("Amstrad GX4000"));
	l_system->setDescription(_("Console released by Amstrad in 1990 and was based on the still-popular CPC technology."));
	l_system->setIconFile(GELIDE_PIXMAPS"amstrad-gx4000.png");
	l_system->setRomsDir("/var/emulation/roms/cpc");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" gx4000 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" gx4000 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Coleco - ColecoVision
	 */
	l_system = new CSystem();
	l_system->setName(_("Coleco ColecoVision"));
	l_system->setDescription(_("Coleco Industries' second generation video game console released in August 1982"));
	l_system->setIconFile(GELIDE_PIXMAPS"coleco-colecovision.png");
	l_system->setRomsDir("/var/emulation/roms/cpc");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" coleco -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" coleco -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" coleco -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Amiga - Commodore
	 */
	l_system = new CSystem();
	l_system->setName(_("Commodore Amiga"));
	l_system->setDescription(_("Amiga Corporation' intented fusion of a computer and video game console released in 1985 as Amiga Commodore"));
	l_system->setIconFile(GELIDE_PIXMAPS"commodore-amiga.png");
	l_system->setRomsDir("/var/emulation/roms/uae");
	// Emulador UAE original
	l_emulator.setId(0);
	l_emulator.setName(_("UAE"));
	l_emulator.setDescription(_("Unix Amiga Emulator, firts emulator for Commodore Amiga started as Unnusable Amiga Emulator at 1995"));
	l_emulator.setVersion("0.8.29");
	l_emulator.setAuthor(_("Bernd Schmidt"));
	l_emulator.setHomepage("");
	l_emulator.setPath("/usr/bin/uae"); // here due in that times there's no inclusion of emulators as games (i really thing emulator are not game)
	l_emulator.setParams(" -s gfx_fullscreen_amiga=no floppy1=\"$gf\" "); // let floppy default and load the software as additional floppy 1
	l_emulator.setIconFile(GELIDE_PIXMAPS"uae.png");
	l_system->addEmulator(l_emulator);
	// Emulador FS-UAE
	l_emulator.setId(0);
	l_emulator.setName(_("Fs-UAE"));
	l_emulator.setDescription(_("Frode Solheim - Unix Amiga Emulator its the evolution from original UAE emulator"));
	l_emulator.setVersion("2.5.37");
	l_emulator.setAuthor(_("Frode Solheim"));
	l_emulator.setHomepage("http://fs-uae.net");
	l_emulator.setPath("/usr/bin/fs-uae");
	l_emulator.setParams(" --fullscreen=0 --floppy_drive_0=\"$gf\" --floppies_dir=\"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"fs-uae.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Emerson - Arcadia 2001
	 */
	l_system = new CSystem();
	l_system->setName(_("Emerson Arcadia 2001"));
	l_system->setDescription(_("A 8-Bits Second generation video game console"));
	l_system->setIconFile(GELIDE_PIXMAPS"emerson-arcadia2001.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("arcadia -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("arcadia -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("arcadia -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Entex - Adventure Vision
	 */
	l_system = new CSystem();
	l_system->setName(_("Entex Adventure Vision"));
	l_system->setDescription(_("Entex's second generation video game console"));
	l_system->setIconFile(GELIDE_PIXMAPS"entex-adventurevision.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("advision -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("advision -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("advision -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Fairchild - Channel F
	 */
	l_system = new CSystem();
	l_system->setName(_("Fairchild Channel F"));
	l_system->setDescription(_("Game console released by Fairchild in 1976. It was the first programmable ROM cartridge console."));
	l_system->setIconFile(GELIDE_PIXMAPS"fairchild-channelf.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("channelf -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("channelf -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("channelf -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  GCE - Vectrex
	 */
	l_system = new CSystem();
	l_system->setName(_("GCE Vectrex"));
	l_system->setDescription(_("8-Bits console with an integrated vector monitor which displays vector graphics"));
	l_system->setIconFile(GELIDE_PIXMAPS"gce-vectrex.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("vectrex -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("vectrex -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("vectrex -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Magnavox - Odyssey2
	 */
	l_system = new CSystem();
	l_system->setName(_("Magnavox Odyssey2"));
	l_system->setDescription(_("Magnavox second generation video game console released in 1978"));
	l_system->setIconFile(GELIDE_PIXMAPS"magnavox-odyssey2.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("odyssey2 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("odyssey2 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("odyssey2 -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Mattel - Intellivision
	 */
	l_system = new CSystem();
	l_system->setName(_("Mattel Intellivision"));
	l_system->setDescription(_("Video game console released by Mattel Electronics in 1979"));
	l_system->setIconFile(GELIDE_PIXMAPS"mattel-intellivision.png");
	l_system->setRomsDir("/var/emulation/roms/int");
	// Emulador jzIntv
	l_emulator.setId(0);
	l_emulator.setName(_("jzIntv"));
	l_emulator.setDescription(_("Joe Zbiciak's Intellivision Emulator for Linux"));
	l_emulator.setVersion("1.0-beta3");
	l_emulator.setAuthor(_("Joe Zbiciak"));
	l_emulator.setHomepage("http://spatula-city.org/~im14u2c/intv");
	l_emulator.setPath("/usr/bin/jzintv");
	l_emulator.setParams("-e \"$bp/exec.bin\" -g \"$bp/grom.bin\" -z1 -f0 \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"jzintv.png");
	l_system->addEmulator(l_emulator);
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams(" intv -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams(" intv -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams(" intv -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  Raine: Rainbow Island Emulator
	 */
	l_system = new CSystem();
	l_system->setName(_("Raine"));
	l_system->setDescription(_("M680x0 Arcade Emulation"));
	l_system->setIconFile(GELIDE_PIXMAPS"arcade-raine.png");
	// Emulador raine
	l_emulator.setId(0);
	l_emulator.setName(_("Raine Type1"));
	l_emulator.setDescription(_("Multi arcade emulator mainly focused on Taito and Jaleco hardware"));
	l_emulator.setVersion("0.51.7");
	l_emulator.setAuthor(_("Antiriad And Raine Team"));
	l_emulator.setHomepage("http://rainemu.swishparty.co.uk/");
	l_emulator.setPath("/usr/bin/raine1");
	l_emulator.setParams(" -nogui -game $gn");
	l_emulator.setIconFile(GELIDE_PIXMAPS"raine.png");
	l_system->addEmulator(l_emulator);
	// Emulador raine
	l_emulator.setId(0);
	l_emulator.setName(_("Raine Type2"));
	l_emulator.setDescription(_("Multi arcade emulator mainly focused on Taito and Jaleco hardware"));
	l_emulator.setVersion("0.51.7");
	l_emulator.setAuthor(_("Antiriad And Raine Team"));
	l_emulator.setHomepage("http://rainemu.swishparty.co.uk/");
	l_emulator.setPath("/usr/bin/raine2");
	l_emulator.setParams(" -nogui -game $gn");
	l_emulator.setIconFile(GELIDE_PIXMAPS"raine.png");
	l_system->addEmulator(l_emulator);
	// Emulador MAME
	l_emulator.setId(0);
	l_emulator.setName(_("Mame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("Nicola Salmoria and the Mame Team"));
	l_emulator.setHomepage("http://www.mamedev.org/");
	l_emulator.setPath("/usr/bin/mame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mame.png");
	l_system->addEmulator(l_emulator);
	// Emulador SdlMame
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMame"));
	l_emulator.setDescription(_("Portable MAME version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert, R. Belmont and the MAME Team"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmame");
	l_emulator.setParams(" -antialias -sound -skip_gameinfo -multithreading -video opengl -keepaspect -rompath \"$gp\" \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmame.png");
	l_system->addEmulator(l_emulator);
	// Emulador XMame
	l_emulator.setId(0);
	l_emulator.setName(_("XMame"));
	l_emulator.setDescription(_("Multiple Arcade Machine Emulator for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame Team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmame");
	l_emulator.setParams(" -vidmod 0 -ef 1 -aa -ka -doublebuf -rp \"$gp\" -skip_gameinfo \"$gf\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmame.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

	/*
	 *  RCA - Studio II
	 */
	l_system = new CSystem();
	l_system->setName(_("RCA Studio II"));
	l_system->setDescription(_("Video game console made by RCA that debuted in January 1977"));
	l_system->setIconFile(GELIDE_PIXMAPS"rca-studio2.png");
	// Emulador mess
	l_emulator.setId(0);
	l_emulator.setName(_("Mess"));
	l_emulator.setDescription(_("Multi Emulator Super System, the sister project of MAME"));
	l_emulator.setVersion("0.139");
	l_emulator.setAuthor(_("The MESS Team"));
	l_emulator.setHomepage("http://www.mess.org/");
	l_emulator.setPath("/usr/bin/mess");
	l_emulator.setParams("studio2 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"mess.png");
	l_system->addEmulator(l_emulator);
	// Emulador sdlmess
	l_emulator.setId(0);
	l_emulator.setName(_("SdlMess"));
	l_emulator.setDescription(_("Portable Mess version for POSIX-y systems with SDL"));
	l_emulator.setVersion("0.136");
	l_emulator.setAuthor(_("Olivier Galibert and R. Belmont"));
	l_emulator.setHomepage("http://rbelmont.mameworld.info/?page_id=163");
	l_emulator.setPath("/usr/bin/sdlmess");
	l_emulator.setParams("studio2 -keepaspect -skip_gameinfo -sound -multithreading -video opengl -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"sdlmess.png");
	l_system->addEmulator(l_emulator);
	// Emulador xmess
	l_emulator.setId(0);
	l_emulator.setName(_("XMess"));
	l_emulator.setDescription(_("Multiple Emulator Super System for UNIX/Linux"));
	l_emulator.setVersion("0.106");
	l_emulator.setAuthor(_("The XMame team"));
	l_emulator.setHomepage("http://x.mame.net");
	l_emulator.setPath("/usr/bin/xmess");
	l_emulator.setParams("studio2 -fullscreen -ef 1 -ka -skip_warnings -skip_gameinfo -doublebuf -cart \"$gf\" -bp \"$bp\"");
	l_emulator.setIconFile(GELIDE_PIXMAPS"xmess.png");
	l_system->addEmulator(l_emulator);
	addSystem(*l_system);

}
