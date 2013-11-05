/*
 * Licensed under the MIT License (MIT)
 *
 * Copyright (c) 2013 AudioScience Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * timer.h
 *
 * Timer class
 */

#pragma once
#ifndef _AVDECC_CONTROLLER_LIB_TIMER_H_
#define _AVDECC_CONTROLLER_LIB_TIMER_H_

#include "avdecc_lib_os.h"

namespace avdecc_lib
{
	class timer
	{
	private:
		bool running;
		bool elapsed;
		uint32_t count;
		avdecc_lib_os::aTimestamp start_time;

	public:
		/**
		 * An empty constructor for timer
		 */
		timer();

		/**
		 * Destructor for timer used for destroying objects
		 */
		~timer();

		avdecc_lib_os::aTimestamp clk_monotonic(void);

		uint32_t clk_convert_to_ms(avdecc_lib_os::aTimestamp timestamp);

		void start(int duration_ms);

		void stop();

		int timeout();
	};
}

#endif
