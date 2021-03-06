/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
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

#ifndef _CRC32_HPP_
#define _CRC32_HPP_

#include <glibmm/ustring.h>

/**
 * Cálculo y transformaciones del CRC32 utilizando el mismo polinomio que
 * programas como WinZip y PKZIP. Este es el tipo de crc utilizado en los
 * archivos .zip.
 */
class CCrc32
{
public:

	/** Tipo para representar el crc */
	typedef unsigned long TCrc32;

	/**
	 * Calcula el crc32 de un fichero dado
	 * @param p_file Path al fichero del que calcular su crc
	 * @return crc32 calculado
	 */
	static TCrc32 getCrc32(const Glib::ustring p_file);

	/**
	 * Calcula el crc32 de los datos en un buffer
	 * @param p_data Comienzo del buffer de datos
	 * @param p_size Tamaño del buffer de datos
	 * @return crc32 calculado
	 */
	static TCrc32 getCrc32(char* p_data, const unsigned int p_size);

	/**
	 * Calcula el crc32 de los datos en un buffer continuando un crc previo
	 * @param p_data Comienzo del buffer de datos
	 * @param p_size Tamaño del buffer de datos
	 * @param p_crc Crc32 de entrada
	 * @return crc32 calculado
	 * @note Después de finalizar hay que llamar a getCrc32Finalize
	 */
	static TCrc32 getCrc32(char* p_data, const unsigned int p_size, const TCrc32 p_crc);

	/**
	 * Finaliza el cálculo de un crc32 realizado con getCrc32 con continuación
	 * @param p_crc Crc32 a finalizar
	 */
	inline static TCrc32 getCrc32Finalize(const TCrc32 p_crc);

	/**
	 * Convierte un crc32 en una cadena de texto a TCrc32 (unsigned long)
	 * @param p_crc Cadena de texto conteniendo el crc
	 * @return crc32 convertido
	 */
	static TCrc32 fromString(const Glib::ustring p_crc);

	/**
	 * Obtiene la representación textual de un crc32
	 * @param p_crc Crc32 del que obtener su representación
	 * @return representación textual del crc
	 * @note El método siempre utiliza digitos hexadecimales en minúscula
	 */
	static Glib::ustring toString(TCrc32 p_crc);

private:
	static const TCrc32 m_crc_table[];	/**< Tabla de generada con el polinomio
											 utilizado por WinZip y PKZIP */
	static const char m_hex_table[];	/**< Tabla con caracteres hexadecimales
											 para toString */
};

#endif // _CRC32_HPP_
