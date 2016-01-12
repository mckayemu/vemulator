Emulao: VenenuX folk from Gelide 1.X brand
===============

## Tabla de contenidos:
-------------------

* 1. [Acerca de Gelide/Emulao](#1-acerca-de-gelideemulao)
* 1.1 [Y como funciona?](#11-y-como-funciona)
* 2. [Características](#2-características)
* 3. [Estado + Sistemas Emuladores](#3-estado--sistemas-emulados)
* 3.1  [Diferencias respeto gelide y emulao](#31-cambios-respecto-gelide-original-y-venenux)
* 4. [Proyecto](#4-proyecto-y-contribuciones)
* 5. [Instalación](#5-instalación)
* 5.1 [Dependencias](#51-dependencias)
* 6. [Acerca de las Roms](#6-acerca-de-las-roms)
* 7. [Ficheros Dat](#7-ficheros-dat)
* 8. [Disclaimer]
* 9. [Agradecimientos]
* 10. [Licencia]



## 1. Acerca de Gelide/Emulao

Este es un folk de la rama GTK2 (Gelide 1.X) de la interfaz para emulacion.
Gelide es un frontend multi sistema y multi emulador que te permitirá
gestionar cualquier tipo de sistema emulado (ordenador, consola, arcade, etc)
así como catalogar y lanzar cualquier juego para el que exista un emulador bajo
Gnu/Linux. Fue creado por Copyright (C) 2008-2011 Juan Ángel Moreno Fernández 
y esta version aqui es especifica para Debian VenenuX y Debian lenny/squeeze.

Te permite configurar cualquier emulador que soporte parámetros por linea de
comandos, sin tener que recordarlos una y otra vez simplificando así su uso.

Gelide es un proyecto libre, licenciado bajo la GNU General Public Licence 
(ver el archivo COPYING para obtener más información) y escrito en C++
utilizando como base las librerías Gtkmm.

Visita la web del proyecto en http://gelide.sf.net para versiones que 
funcionen con Linux mas modernos, esta es para GTK2 y muchos mas emuladores!



### 1.1 Y como funciona?

Gelide tiene 3 paneles, uno de la consola/sistema (Arriba izquierda-centro) 
otro del emulador (abajo del de los sistemas) y los roms (al lado de los sistemas/consolas), 
selecciona cada apartado (sistema, emulador y rom a jugar) despues pulsar enter sobre 
el rom y lanzara el emulador para jugar el rom seleccionado.

MAS FACIL IMPOSIBLE!!!

Los roms o juegos aparecen despues de generar su listado, desde el apartado de 
las consolas/sistemas a emular con un click de menu, de cada consola los roms deberan 
estar en /var/emulation/roms, si se prefiere otro lugar se define editando este partado.

Los apartados de sistemas/consolas y emulador son editables para modificar las 
opciones de lineas de comando que acepta cada emulador o los datos de la consola/sistema 
que emula, tambien se pueden agrear nuevas consolas y nuevos emuladores por consolas.



## 2. Características

* Gui simple, gestión de sistemas, emuladores y juegos mediante menús simples.
* Multiproceso, cada emulacion ejhecutada es un hilo propio desde la gui.
* Configuración de cualquier emulador que soporte parámetros por linea comandos.
* Para cada sistema es posible configurar cualquier número de emuladores.
* Soporta la inserción de datos de juegos desde ficheros DAT. Actualmente
  soporta tres formatos: ClrMamePro, Mame XML, Logiqx XML.
* Realiza chequeo y comparación simple de los juegos contra ficheros dat.
* Incluye previsualización de imágenes de los juegos (Captura, Titulo,
  Frontal, Trasera y Medio).
* Soporta imágenes del juego por nombre o crc lo cual permite soportar los
  sets de imágenes del "no-intro screenshot archive".
* Permite exportar e importar las configuraciones de sistemas (incluyendo 
  las configuracioens de sus emuladores).
* Incluye un panel de filtros para los listados de juegos.
* Soporta filtrado de juegos por nombre.
* Modo pantalla completa.



## 3. Estado + Sistemas Emulados

Actualmente Gelide está pausado, Vemulao solo adiciona necesidades y emuladores, intentando siempre corregir errores.
Emulao actualmente lanza los emuladores, lista los roms y preconfigura sus opciones "al lanzar" el emulador con el rom..

Vemulao respecto Gelide ebn la serie GTK2 (1.X), lleva incorporados un total de 40 sistemas y 38
emuladores diferentes, preconfigurados de la siguiente manera:
TODO esto se ampliara con enlaces a la wiki y secciones especificas.

* Amstrad GX4000:
	Mess, Sdlmess
* Atari 2600:
	Stella, z26, Mess, Sdlmess, Xmess
* Atari 5200:
	Mess, Sdlmess, Xmess
* Atari 7800:
	Mess, Sdlmess, Xmess
* Atari Jaguar:
	Virtual Jaguar, Mess, Sdlmess
* Atari Lynx:
	Mednafen, Sdlmess, Handy/SLD, Mess, Xmess
* Bandai Wonderswan:
	Mednafen, Xe, Mess, Sdlmess, Xmess
* Bandai Wonderswan Color:
	Mednafen, Xe, Mess, Sdlmess, Xmess
* Coleco ColecoVision:
	Mess, Sdlmess, Xmess
* Commodore Amiga:
	UAE, fs-uae, e-UAE, Mess, Sdlmess, Xmess
* Emerson Arcadia 2001:
 	Mess, Sdlmess, Xmess
* Entex Adventure vision:
 	Mess, Sdlmess, Xmess
* Fairchild Channel F:
 	Mess, Sdlmess, Xmess
* GCE Vectrex:
 	Mess, Sdlmess, Xmess
* Magnavox Odyssey2:
	Mess, Sdlmess, Xmess
* Mame:
 	Mame, Sdlmame, Xmame
* Mattel Intellivision:
	Mess, Sdlmess, Xmess, jzIntv
* NEC Pc Engine:
	Mednafen, Hu-go!, Xe, Mess, Sdlmess, Xmess
* NEC Super Grafx:
	Mednafen, Mess, Sdlmess
* Nintendo DS:
	DeSMuME
* Nintendo Famicom Disk system:
 	FCEUX, Mednafen, Fceu, Xe, Mess, Sdlmess
* Nintendo Game Boy:
 	Mednafen, VisualBoyAdvance, Xe, Mess, Sdlmess, Xmess
* Nintendo Game Boy Color:
 	Mednafen, VisualBoyAdvance, Xe, Mess, Sdlmess, Xmess
* Nintendo Game Boy Advance:
 	Mednafen, VisualBoyAdvance, Xe, Mess, Sdlmess
* Nintendo Entertaninment System (NES):
 	FCEUX, Mednafen, Fceu, Xe, Mess, Sdlmess
* Nintendo Super Nintendo Entertaninment System (SNES):
 	Snes9x, Mednafen, SNes9x-gtk, Zsnes, Xe, Mess, Sdlmess, Xmess
* Nintendo 64:
 	Mupen64Plus, Mupen64, Mess, Sdlmess
* Nintendo Virtual Boy:
 	Mednafen, Mess, Sdlmess
* Raine:
	Raine, Mame, Sdlmame, XMame
* RCA Studio II:
	Mess, Sdlmess, Xmess
* SEGA 32X:
	Gens, Gens/GS, Mess, Sdlmes
* SEGA Game Gear:
 	Mednafen, Osmose, Xe, Mess, Sdlmess
* SEGA Master System:
 	Mednafen, Osmose, Xe, Mess, Sdlmess, Xmess
* SEGA Mega Drive:
 	Dgen, Gens, Gens/GS, Regen, Xe, Generator, Mess, Sdlmess, Xmess
* SEGA SG-1000:
 	Mednafen, Xe, Mess, Sdlmess
* Sinclair ZX Spectrum:
	FBZX, Fuse, SpectEmu, Mess, SdlMess
* SNK Neo Geo:
	GnGeo, Mame, Sdlmame, XMame 
* SNK Neo Geo Pocket:
	Mednafen, Xe, Mess, Sdlmess
* SNK Neo Geo Pocket Color:
	Mednafen, Xe, Mess, Sdlmess
* ZiNc:
	ZiNc, Mame, Sdlmame, XMame

### 3.1 Cambios respecto gelide original y VenenuX

A) Directorio de roms:
 Todos los modulos/emuladores estan preconfigurados con su ROM directorio y abren en ventana.

B) Emuladores Ajustados:
 Se cambio tres emuladores, bsnes, Gambate y boycott se removieron por ser complicados y 
 ofrecer lo mismo que mednafen, en la mayoria se establece mednafen como primario para lograr 
 homogeneidad al emular y el usuario no se pierda (especialmente con los salvados)
 Se agrego tres emuladores, los viejos fceu, mupen64 y se dividio mednafen entre el 0.8 y 0.9.

C) Sistemas mas usados ordenados
 Los emuladores mas usados o populares estan ordenados como primeros y los menos populares 
 se colocaron al final de la lista. ***Se tienen pendientes mas emuladores y sistemas que estan incluso 
 desaparecidos del mundo de linux.***



## 4. Proyecto y contribuciones

Vemulao (emulao) es un folk especifico del Gelide. Esta modificado para ser usado en VenenuX

Gelide es un proyecto hospedado en sourceforge.net. Recientemente se mudo 
a un hospedaje en github 
https://github.com/tapule/Gelide

Otra forma de ayudarnos es con la traducción de otros documentos del
proyecto, como por ejemplo "doc/Systems&Emulators-HowTo.es_ES.txt" o este mismo
que estás leyendo.

También puede ser interesante que nos remitas tus configuraciones de 
sistemas y emuladores que no vienen preconfigurados en Gelide, o aquellos para
los que crees que has encontrado unos parámetros más adecuados para su uso. Solo
tienes que exportarlos desde Gelide (Menú Archivo -> Exportar sistemas) y
enviarnos los archivos exportados a la dirección de correo del proyecto
<gelide.prj@gmail.com>.


## 5. Instalación

Para Debian y VenenuX solo agregar el repositorio VenenuX y "apt-get install emulao"

Las instrucciones comunes para linux usando las fuentes, en el archivo INSTALL
en la raiz del archivo tarball con el código fuente del programa. Para compilar
Gelide desde los fuentes necesitarás como mínimo Gtkmm 2.6.x instalado en tu
sistema además de las autotools y lo necesario para compilar aplicaciones en
C/C++ bajo GNU/Linux.

### 5.1. Dependencias

Gelide en su versión actual, solo depende de las librerías libgtkmm (que a su vez depende de gtk y este glib)
y libxml2, no obstante para compilar desde los archivos fuente, necesitarás tener
instaladas las versiones de desarrollo de estas dos librerías (-dev) y también
la utilidad intltool.


## 6. Acerca de las Roms

Gelide está desarrollado sin ningún ánimo más alla de mi propia inquietud
por la programación y el mundo GNU/Linux y PARA NADA está a favor del uso ilegal
de Roms. Si no tienes el juego original, no estás autorizado a jugar con la Rom
del juego por lo que no me preguntes donde conseguir Roms ni cualquier otro tema
relacionado, no responderé.
Hay multitud de roms legales, libres y gratis, googlea un poco y las podrás
encontrar sin dificultad.


## 7. Ficheros Dat

Los archivos Dat, son una especie de base de datos donde se almacena 
información referente a un sistema, sus juegos y los datos de sus roms. Son
utilizados, o más bien requeridos, por gestores de Roms (Roms managers) tales
como ClrMamePro y RomCenter para poder construir y auditar los sets de roms para
que sean usables por los emuladores.

Hay vários formatos de archivos dat tales como ClrMamePro dat, Mame XML,
Logiqx XML, RomCenter 1, RomCenter 2, etc. aunque tanto la versión actual del
ClrMamePro como del RomCenter parecen estar dando soporte a los formatos basados
en XML como el Dat XML genérico que parece haber surgido desde la web
http://www.logiqx.com, aunque de esto no estoy muy seguro.

La versión actual de Gelide soporta ficheros dat en formato ClrMamePro, Mame
XML, Logiqx XML, aunque no es capaz de auditar roms. Estos dats se usan para
obtener los datos de un sistema determinado y para realizar una comparación con
las roms del usuario basada en el nombre del fichero para establecer algunos
flags del listado de juegos.

Estos son algunos de los lugares donde se pueden obtener ficheros dat:

* http://www.no-intro.org/datset.htm: Dats del grupo No-Intro posiblemente
  los mejores y más limpios dats de internet.
* http://www.romshepherd.com: Una gran recopilación de dats.
* http://www.emuxhaven.net/cowering.shtml: Recopilación de dats basados en
  las GoodTools
* http://www.4shared.com/dir/795431/2c9f835/sharing.html: Una buena
  recopilación de dats.
* http://www.logiqx.com/Dats: Buena recopilación de dats Arcade.
* http://emulationrealm.net/modules/wfdownloads/viewcat.php?op=&cid=275:
  Recopilación extensa de ficheros dats en diferentes formatos.


## 8. Disclaimer

Ni mi perro ni yo, nos hacemos responsables de lo que te pueda pasar a ti o
a tu ordenador, por utilizar Gelide. Esta claro ¿no?.

Ni VenenuX ni los mapurites que ya no quieren contribuir sino solo cuando les 
conviene se hacen responsables de lo que pueda pasar usando este software. Asi como estilo 
mocosoft que nunca estan cuando se les necesita.


## 9. Agradecimientos

A Minisoriex Vimatoga por sus ideas y ayuda.
A JesusDa por darme la idea para los nombres de las versiones.
A Tom G.P. por ponerme en la pista de los emuladores Regen y Gambatte.
A Loris Cuoghi, Emeric Grange, Niklas Grahn, Manuel Wächter,
Daniel Nylander, Kamil Ślepowroński, Oleg Koptev por sus esfuerzos para traducir
Gelide a otros idiomas.
A Pablo Casas (pablo33) por todas sus sugerencias y por reportar el solo
prácticamente todos los bugs de la versión 0.1.4. 
Quiero dar las gracias muy especialmente a todas y cada una de las personas
que participan o han participado en el diseño e implementación de un emulador,
así como a todas aquellas personas que han pasado horas y horas documentando el
funcionamiento de un sistema determinado, sin vosotros el mundo de la emulación
no existiría. 


## 10. Licencia

Gelide
Copyright (C) 2008-2011 Juan Ángel Moreno Fernández

Gelide is free software.

You can redistribute it and/or modify it under the terms of the GNU General
Public License, as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.

Gelide is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.
See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
Gelide. If not, see <http://www.gnu.org/licenses/>


-------------------------------------------------------------------------------

Para obtener más información, visita la página web del proyecto, que podrás 
encontrar en:
https://github.com/tapule/Gelide

Para mas info de la version especifica de VenenuX visita los grupos de venenux en googlegroups.

-------------------------------------------------------------------------------

