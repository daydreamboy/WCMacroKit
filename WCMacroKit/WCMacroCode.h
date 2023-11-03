//
//  WCMacroCode.h
//  WCMacroKit
//
//  Created by wesley_chen on 2020/3/5.
//

#ifndef WCMacroCode_h
#define WCMacroCode_h

// Code wrapper

/**
 Make code block run on main thread
 
 @param ... the code block
 */
#define CODE_SAFE_RUN_ON_MAIN_THREAD(...) \
do { \
    dispatch_block_t block_interal = ^{ \
        __VA_ARGS__; \
    }; \
    if ([NSThread isMainThread]) { \
        block_interal(); \
    } \
    else { \
        dispatch_async(dispatch_get_main_queue(), ^{ \
            block_interal(); \
        }); \
    } \
} while (0);

#pragma mark - Debug

#if DEBUG
static inline void s_debug_function(void (^block)(void)) {
    if (block) {
        block();
    }
}
#else
#endif

#if DEBUG
#define CODE_RUN_IN_DEBUG \
s_debug_function
#else

#define CODE_RUN_IN_DEBUG_EXPANDED_1(counter_) \
__unused void (^block_internal_##counter_)(void) =

// @see https://stackoverflow.com/questions/12690639/counter-in-variable-name
#define CODE_RUN_IN_DEBUG_1(x) \
CODE_RUN_IN_DEBUG_EXPANDED_1(x)

#define CODE_RUN_IN_DEBUG \
CODE_RUN_IN_DEBUG_1(__COUNTER__)
#endif

#pragma mark - Custom Method Prefix

#pragma mark > OC Category Method Prefix

#ifndef WCMethodPrefixed
// @see https://stackoverflow.com/questions/23021074/macro-as-a-parameter-to-another-macro
#define _WCMethodPrefixed(prefix_, ...) prefix_##_##__VA_ARGS__
/**
 Create a prefixed OC method
 
 @param prefix_ the prefix
 @param ... the method signature
 
 @discussion This macro use the format `<prefix>_<method signature>` to create a prefixed OC method
 */
#define WCMethodPrefixed(prefix_, ...) _WCMethodPrefixed(prefix_, __VA_ARGS__)
#endif

#pragma mark > OC Category Method Call Prefix

#ifndef WCMethodCallPrefixed

#define _WCMethodCallPrefixed(prefix_, ...) prefix_##_##__VA_ARGS__
/**
 Create a prefixed OC method call
 
 @param prefix_ the prefix
 @param ... the method signature
 
 @discussion This macro use the format `<prefix>_<method signature>` to create a prefixed OC method
 */
#define WCMethodCallPrefixed(prefix_, ...) _WCMethodCallPrefixed(prefix_, __VA_ARGS__)
#endif


#pragma mark > OC Selector Prefix

#ifndef WCSelectorPrefixed

#define _WCSelectorPrefixed(prefix_, ...) @selector(prefix_##_##__VA_ARGS__)
/**
 Create a prefixed OC selector
 
 @param prefix_ the prefix
 @param ... the selector
 
 @discussion This macro use the format `@selector(<prefix>_<selector>)` to create a prefixed OC selector
 */
#define WCSelectorPrefixed(prefix_, ...) _WCSelectorPrefixed(prefix_, __VA_ARGS__)
#endif

#pragma mark - Check Value

/**
 The begin of BEGIN/END pair
 
 @param type_ the variable type
 @param outputVar_ the variable for output
 @param initialValue_ the initial value for output variable
 */
#define CHECK_VALUE_BEGIN(type_, outputVar_, initialValue_) \
type_ outputVar_ = ({ \
type_ resultVar_ = (initialValue_); \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wunused-variable\"") \
    type_ tempValue_ = nil; \
_Pragma("clang diagnostic pop") \

/**
 @param expression_ the expression to assign variable
 @param condition_ the condition for checking if the expression should assign variable
 */
#define CHECK_VALUE_CASE(expression_, condition_) \
tempValue_ = (expression_); \
if ((condition_)) { resultVar_ = tempValue_; break; } \

/**
 The end of BEGIN/END pair
 */
#define CHECK_VALUE_END \
} while (NO); \
resultVar_; \
});

#endif /* WCMacroCode_h */
