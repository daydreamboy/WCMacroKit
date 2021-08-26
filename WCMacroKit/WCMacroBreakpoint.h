//
//  WCMacroBreakpoint.h
//  WCMacroKit
//
//  Created by wesley_chen on 2021/2/25.
//

#import "WCMacroAttribute.h"

#ifndef WCMacroBreakpoint_h
#define WCMacroBreakpoint_h

#pragma mark - Breakpoint

// Note: Don't use MAKE_TRAP() macro directly
// for arm64 device
#if defined(__APPLE__) && defined(__aarch64__)

#define MAKE_TRAP() __asm__ __volatile__(     \
"   mov    x0, %x0;    \n" /* pid                */ \
"   mov    x1, #0x11;  \n" /* SIGSTOP            */ \
"   mov    x16, #0x25; \n" /* syscall 37 = kill  */ \
"   svc    #0x80       \n" /* software interrupt */ \
"   mov    x0, x0      \n" /* nop                */ \
::  "r"(getpid())                                   \
:   "x0", "x1", "x16", "memory")

// for armv7 device
#elif defined(__APPLE__) && defined(__arm__)
#define MAKE_TRAP() __asm__ __volatile__(     \
"   mov    r0, %0;     \n" /* pid                */ \
"   mov    r1, #0x11;  \n" /* SIGSTOP            */ \
"   mov    r12, #0x25; \n" /* syscall 37 = kill  */ \
"   svc    #0x80       \n" /* software interrupt */ \
"   mov    r0, r0      \n" /* nop                */ \
::  "r"(getpid())                                   \
:   "r0", "r1", "r12", "memory")

// for simulator(32 bit/64 bit)
#elif defined(__APPLE__) && (defined(__i386__) || defined(__x86_64__))

#define MAKE_TRAP() __asm__ __volatile__( \
"int $3;" \
"mov %eax, %eax")

#endif // #if defined(__APPLE__) && defined(__aarch64__)

#if DEBUG

/**
 The toggle for disable the BREAKPOINT_MAKE_ON_DEBUG globally
 
 @note Set sDisableGlobalBreakpointMakeOnDebug to YES at any .m file only once.
 Default value is NO
 
 @example
 BOOL sDisableGlobalBreakpointMakeOnDebug = YES;
 */
extern BOOL sDisableGlobalBreakpointMakeOnDebug;

/**
 Make a breakpoint in code and can resume by LLDB's continue command
 
 @param condition_ If NO will trigger the breakpoint on this macro, YES will pass
 @param comment_ the comment string
 
 @warning This maco only works on DEBUG mode. Don't use it on production code.
 */
#define BREAKPOINT_MAKE_ON_DEBUG(condition_, comment_) \
do { \
    if (sDisableGlobalBreakpointMakeOnDebug == NO && !(condition_)) { \
        NSLog(@"[WCMacroKit] %@", comment_); \
        MAKE_TRAP(); \
    } \
} while(0);

#else // #if DEBUG

#define BREAKPOINT_MAKE_ON_DEBUG(condition_, comment_)

#endif // #if DEBUG


#endif /* WCMacroBreakpoint_h */
