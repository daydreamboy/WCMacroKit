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

#endif /* WCMacroCode_h */
