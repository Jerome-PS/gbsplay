/*
 * gbsplay is a Gameboy sound player
 *
 * 2003-2021 (C) by Tobias Diedrich <ranma+gbsplay@tdiedrich.de>
 *
 * Licensed under GNU GPL v1 or, at your option, any later version.
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include "config.h"
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef uint64_t cycles_t;

/* mingw64 also defines __MINGW32__ in addition to __MINGW64__ */
#ifdef __MINGW32__
#define HAVE_MINGW 1
#endif

#ifndef true
#define true (0==0)
#define false (!true)
#endif

#define UNUSED(x) (void)(x)

#define WARN_N(n, ...) { \
	static long ctr = n; \
	if (ctr) { \
		ctr--; \
		fprintf(stderr, __VA_ARGS__); \
	} \
}
#define WARN_ONCE(...) WARN_N(1, __VA_ARGS__)

#define CONTAINER_OF(ptr, type, member) \
	((type *)((void *)(ptr) - offsetof(type, member)))

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#define TEXTDOMAIN "gbsplay"
#define N_(x) x

#define LN2 .69314718055994530941
#define MAGIC 5.78135971352465960412
#define FREQ(x) (262144 / (x))
#define NOTE(x) ((long)((log(FREQ(x))/LN2 - MAGIC)*12 + .2))

#if USE_I18N == 1

#  include <locale.h>
#  include <libintl.h>

#  if GBS_PRESERVE_TEXTDOMAIN == 1

static inline char* _(const char* const msgid)
{
	char *olddomain = textdomain(NULL);
	char *olddir = bindtextdomain(olddomain, NULL);
	char *res;

	bindtextdomain(TEXTDOMAIN, LOCALE_PREFIX);
	res = dgettext(TEXTDOMAIN, msgid);
	bindtextdomain(olddomain, olddir);

	return res;
}

#  else

static inline char* _(const char* const msgid)
{
	return gettext(msgid);
}

static inline void i18n_init(void)
{
	if (setlocale(LC_ALL, "") == NULL) {
		fprintf(stderr, "setlocale() failed\n");
	}
	if (bindtextdomain(TEXTDOMAIN, LOCALE_PREFIX) == NULL) {
		fprintf(stderr, "bindtextdomain() failed: %s\n", strerror(errno));
	}
	if (textdomain(TEXTDOMAIN) == NULL) {
		fprintf(stderr, "textdomain() failed: %s\n", strerror(errno));
	}
}

#  endif

#else

#  define _(x) (x)
static inline void i18n_init(void) {}

#endif

#include <sys/param.h>

#ifndef BYTE_ORDER

#  define BIG_ENDIAN 1
#  define LITTLE_ENDIAN 2

#  ifdef _BIG_ENDIAN
#    define BYTE_ORDER BIG_ENDIAN
#  endif

#  ifdef _LITTLE_ENDIAN
#    define BYTE_ORDER LITTLE_ENDIAN
#  endif

#endif /* BYTE_ORDER */

#if !BYTE_ORDER || !BIG_ENDIAN || !LITTLE_ENDIAN
#  error endian defines missing
#endif

#if BYTE_ORDER == BIG_ENDIAN

static inline long is_le_machine() {
	return false;
}

static inline long is_be_machine() {
	return true;
}

#else

static inline long is_le_machine() {
	return true;
}

static inline long is_be_machine() {
	return false;
}

#endif

#endif
