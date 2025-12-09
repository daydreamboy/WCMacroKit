//
//  WCMacroDebug.h
//  WCMacroKit
//
//  Created by wesley_chen on 2025/12/9.
//

#ifndef WCMacroDebug_h
#define WCMacroDebug_h

#include <string.h>

#pragma mark - Private (with double `_`)

// @header #include <string.h>
// @see https://stackoverflow.com/questions/8487986/file-macro-shows-full-path
#ifndef __WC_FILE_NAME__
#define __WC_FILE_NAME__      ((strrchr(__FILE__, '/') ? : __FILE__ - 1) + 1)
#endif

__unused static const char* __wc_string_from_value(const void* value, const char* type) {
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
    if (strcmp(type, "unsigned int") == 0) {
        snprintf(buffer, STRINGIFY_BUFFER_SIZE, "%u", *(const unsigned int*)value);
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
#define __WCGetValueType(v_) \
_Generic((v_), \
char: "char", \
char *: "char *", \
double: "double", \
float: "float",  \
int: "int",  \
long: "long",  \
long long: "long long",  \
long double: "long double", \
unsigned int: "unsigned int", \
default: "unknown"  \
)\


#pragma mark - Dump Value
/**
 Dump primitive value (used in C11+)
 
 @param v_ the value
 */
#define WCDumpPrimitiveValue(v_) fprintf(stderr, "%s:%d: `%s`=`%s` (%s)\n", __WC_FILE_NAME__, (int)__LINE__, #v_, __wc_string_from_value(&v_, __WCGetValueType(v_)), __WCGetValueType(v_))

/**
 Dump YES or NO

 @param o the boolean value
 
 @note using fprintf to dump, not use NSLog
 */
#define WCDumpBool(o) fprintf(stderr, "%s:%d: `%s`=`%s`\n", __WC_FILE_NAME__, (int)__LINE__, #o, (o) ? "YES" : "NO")

/**
 Dump Objective-C object

 @param o the object value
 
 @note using fprintf to dump, not use NSLog
 */
#define WCDumpObject(o_) fprintf(stderr, "%s:%d: `%s`=`%s` (%p:%s)\n", __WC_FILE_NAME__, (int)__LINE__, #o_, ([o_ debugDescription].UTF8String), o_, NSStringFromClass([o_ class]).UTF8String)

/**
 Dump class by name
 
 @param name_ the C string for class name
 
 @header #import <objc/runtime.h>
 */
#define WCDumpClassByName(name_) fprintf(stderr, "%s:%d: `%s`=`%p` (class)\n", __WC_FILE_NAME__, (int)__LINE__, (name_), objc_getClass(name_))

/**
 Dump meta class by name
 
 @param name_ the C string for class name
 
 @header #import <objc/runtime.h>
 */
#define WCDumpMetaClassByName(name_) fprintf(stderr, "%s:%d: `%s`=`%p` (metaClass)\n", __WC_FILE_NAME__, (int)__LINE__, (name_), objc_getMetaClass(name_))

#pragma mark - Debug Log


#endif /* WCMacroDebug_h */
