/* 
 * File:   allocate_sprint.h
 * Author: nvcleemp
 *
 * Created on July 12, 2016, 10:21 AM
 */

#include <stdarg.h>

#ifndef ALLOCATE_SPRINT_H
#define	ALLOCATE_SPRINT_H

#ifdef	__cplusplus
extern "C" {
#endif

int varargs_allocate_sprintf(char **strp, const char *fmt, va_list ap);

int allocate_sprintf(char **strp, const char *fmt, ...);


#ifdef	__cplusplus
}
#endif

#endif	/* ALLOCATE_SPRINT_H */

