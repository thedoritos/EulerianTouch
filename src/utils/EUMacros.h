//
//  EUMacros.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef EulerianTouch_EUMacros_h
#define EulerianTouch_EUMacros_h

/*
 * Delete pointer safely.
 */
#define EU_DELETE(__ptr__)\
if (__ptr__ != 0) {\
delete __ptr__;\
__ptr__ = 0;\
}

/*
 * Print log only if debugging.
 */
#ifdef DEBUG
#define EU_LOG(fmt, ...)\
printf("%s:%d\n", __FILE__, __LINE__);\
printf(fmt, __VA_ARGS__);\
printf("\n")
#else
#define EU_LOG(fmt, ...)
#endif