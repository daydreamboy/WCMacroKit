//
//  WCMacroLog.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroLog_h
#define WCMacroLog_h

#include <stdio.h>
#include <string.h>

#import <objc/runtime.h>


#pragma mark - Private

// @header #include <string.h>
// @see https://stackoverflow.com/questions/8487986/file-macro-shows-full-path
#ifndef __WC_FILE_NAME__
#define __WC_FILE_NAME__      ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1)
#endif

#pragma mark - Log Suite (Alert/Critical/Error/Info/Warning/Notice/Debug)

// DEBUG_LOG
#ifndef DEBUG_LOG
#define DEBUG_LOG 1
#endif

#if DEBUG_LOG

// TODO: Configure module name here...
#define MODULE_NAME        @""

#ifdef MODULE_NAME
#   define MODULE_NAME_STR [NSString stringWithFormat:@"[%@]", MODULE_NAME]
#else
#   define MODULE_NAME_STR @""
#endif

// XLog format: [<log level>][<module name>] <method name>(<filename.m>:<line number>) <log message here...>

#   define ALog(fmt, ...) { NSLog((@"[Alert]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__WC_FILE_NAME__), @(__LINE__),  ## __VA_ARGS__); }
#   define CLog(fmt, ...) { NSLog((@"[Critical]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__WC_FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#   define ELog(fmt, ...) { NSLog((@"[Error]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__WC_FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#   define ILog(fmt, ...) { NSLog((@"[Info]%@ " fmt), MODULE_NAME_STR, ## __VA_ARGS__); }
#   define WLog(fmt, ...) { NSLog((@"[Warning]%@ " fmt), MODULE_NAME_STR,  ## __VA_ARGS__); }

#ifdef DEBUG
#   define NLog(fmt, ...) { NSLog((@"[Notice]%@ " fmt), MODULE_NAME_STR, ## __VA_ARGS__); }
#   define DLog(fmt, ...) { NSLog((@"[Debug]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__WC_FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#else
#   define NLog(fmt, ...)
#   define DLog(fmt, ...)
#endif

/**
 *  Log NSError if needed
 *
 *  @param err a NSError object
 */
#ifndef LogError
#define LogError(fmt, err, ...) \
{ \
    if (err) { \
        ELog(fmt, err, ##__VA_ARGS__); \
    } \
}
#endif

#else /* if DEBUG_LOG */

#   define ALog(fmt, ...)
#   define CLog(fmt, ...)
#   define ELog(fmt, ...)
#   define WLog(fmt, ...)
#   define NLog(fmt, ...)
#   define ILog(fmt, ...)
#   define DLog(fmt, ...)

#   define LogError(err)

#endif /* if DEBUG_LOG */

#pragma mark - Log for Debug Local Code

// WCDebugLog
#if DEBUG
#   define WCDebugLog(fmt, ...) { NSLog((@"%s:%d: " fmt), __WC_FILE_NAME__, __LINE__, ## __VA_ARGS__); }
#else
#   define WCDebugLog(fmt, ...)
#endif

/**
 The log macro with prefix
 
 @discussion This macro must work with another macro WCLogModule.
 Usually you should not use it directly.
 
 @example
 #import <WCMacroKit/WCMacroKit.h>
 #define WCLogModule @"[YourModuleName] "
 #undef WCDebugLog
 #define WCDebugLog WCDebugLogPrefix
 
 WCDebugLog(@"log something");
 */
#define WCDebugLogPrefix(fmt, ...) { NSLog((@"%s:%d: " WCLogModule fmt), __WC_FILE_NAME__, __LINE__, ## __VA_ARGS__); }

#pragma mark - Log for Dump Object (Deprecated)

#define WCLogObject(o)  NSLog(@"%@:%@: `%s`=`%@`", @(__WC_FILE_NAME__), @(__LINE__), #o, (o))
#define WCLogBool(o)  NSLog(@"%@:%@: `%s`=`%@`", @(__WC_FILE_NAME__), @(__LINE__), #o, (o) ? @"YES" : @"NO")

#endif /* WCMacroLog_h */
