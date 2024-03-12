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

// Log Suite

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

#ifndef __FILE_NAME__
#define __FILE_NAME__      ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1)
#endif

// XLog format: [<log level>][<module name>] <method name>(<filename.m>:<line number>) <log message here...>

#   define ALog(fmt, ...) { NSLog((@"[Alert]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__FILE_NAME__), @(__LINE__),  ## __VA_ARGS__); }
#   define CLog(fmt, ...) { NSLog((@"[Critical]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#   define ELog(fmt, ...) { NSLog((@"[Error]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#   define WLog(fmt, ...) { NSLog((@"[Warning]%@ " fmt), MODULE_NAME_STR,  ## __VA_ARGS__); }

#ifdef DEBUG
#   define NLog(fmt, ...) { NSLog((@"[Notice]%@ " fmt), MODULE_NAME_STR, ## __VA_ARGS__); }
#   define ILog(fmt, ...) { NSLog((@"[Info]%@ " fmt), MODULE_NAME_STR, ## __VA_ARGS__); }
#   define DLog(fmt, ...) { NSLog((@"[Debug]%@ %@(%@:%@) " fmt), MODULE_NAME_STR, @(__PRETTY_FUNCTION__), @(__FILE_NAME__), @(__LINE__), ## __VA_ARGS__); }
#else
#   define NLog(fmt, ...)
#   define ILog(fmt, ...)
#   define DLog(fmt, ...)
#endif

/**
 *  Log NSError if needed
 *
 *  @param err a NSError object
 */
#ifndef LogError
#define LogError(err)       \
{                           \
    if (err) {              \
        ELog(@"%@", err);   \
    }                       \
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

#pragma mark - WCDump

/**
 Dump YES or NO

 @param o the boolean value
 
 @note using fprintf to dump, not use NSLog
 */
#define WCDumpBool(o) fprintf(stderr, "%s:%d: `%s`=`%s`\n", ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1), (int)__LINE__, #o, (o) ? "YES" : "NO")

/**
 Dump Objective-C object

 @param o the object value
 
 @note using fprintf to dump, not use NSLog
 */
#define WCDumpObject(o_) fprintf(stderr, "%s:%d: `%s`=`%s` (%p:%s)\n", ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1), (int)__LINE__, #o_, ([o_ debugDescription].UTF8String), o_, NSStringFromClass([o_ class]).UTF8String)

/**
 Dump class by name
 
 @param name_ the C string for class name
 
 @header #import <objc/runtime.h>
 */
#define WCDumpClassByName(name_) fprintf(stderr, "%s:%d: `%s`=`%p` (class)\n", ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1), (int)__LINE__, (name_), objc_getClass(name_))

/**
 Dump meta class by name
 
 @param name_ the C string for class name
 
 @header #import <objc/runtime.h>
 */
#define WCDumpMetaClassByName(name_) fprintf(stderr, "%s:%d: `%s`=`%p` (metaClass)\n", ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1), (int)__LINE__, (name_), objc_getMetaClass(name_))

#pragma mark > WCDumpValue

static const char* wc_string_from_value(const void* value, const char* type) {
#define STRINGIFY_BUFFER_SIZE 1024
    
    static char buffer[STRINGIFY_BUFFER_SIZE];
    memset(buffer, 0, STRINGIFY_BUFFER_SIZE);

    if (strcmp(type, "int") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%d", *(const int*)value);
    }
    else if (strcmp(type, "char") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%c", *(const char*)value);
    }
    else if (strcmp(type, "char *") == 0) {
        strncpy(buffer, (char *)value, STRINGIFY_BUFFER_SIZE - 1);
        buffer[STRINGIFY_BUFFER_SIZE - 1] = '\0';
    }
    else if (strcmp(type, "double") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%f", *(const double*)value);
    }
    else if (strcmp(type, "float") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%f", *(const float*)value);
    }
    else if (strcmp(type, "long") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%ld", *(const long*)value);
    }
    else if (strcmp(type, "long long") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%lld", *(const long long*)value);
    }
    else {
        strncpy(buffer, "<unknown>", STRINGIFY_BUFFER_SIZE - 1);
        buffer[STRINGIFY_BUFFER_SIZE - 1] = '\0';
    }

    return buffer;
    
#undef STRINGIFY_BUFFER_SIZE
}

/**
 Get primitive type of C value
 
 @note this macro used on C11+
 */
#define WCGetValueType(v_) \
_Generic((v_), \
char: "char", \
char *: "char *", \
double: "double", \
float: "float",  \
int: "int",  \
long: "long",  \
long long: "long long",  \
long double: "long double", \
default: "unknown"  \
)\

// C11+
#define WCDumpValue(v_) fprintf(stderr, "%s:%d: `%s`=`%s` (%s)\n", ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1), (int)__LINE__, #v_, wc_string_from_value(&v_, WCGetValueType(v_)), WCGetValueType(v_))


#pragma mark - WCLog

#define WCLogObject(o)  NSLog(@"%@:%@: `%s`=`%@`", @(__FILE_NAME__), @(__LINE__), #o, (o))
#define WCLogBool(o)  NSLog(@"%@:%@: `%s`=`%@`", @(__FILE_NAME__), @(__LINE__), #o, (o) ? @"YES" : @"NO")


// WCLog
#if DEBUG_LOG
#   define WCLog(fmt, ...) { NSLog((fmt), ## __VA_ARGS__); }
#else
#   define WCLog(fmt, ...)
#endif

/**
 The log macro with prefix
 
 @discussion This macro must work with another macro WCLogModule.
 Usually you should not use it directly.
 
 @example
 #import <WCMacroKit/WCMacroKit.h>
 #define WCLogModule @"[YourModuleName] "
 #undef WCLog
 #define WCLog WCLogPrefix
 
 WCLog(@"log something");
 */
#define WCLogPrefix(fmt, ...) { NSLog((WCLogModule fmt), ## __VA_ARGS__); }

#endif /* WCMacroLog_h */
