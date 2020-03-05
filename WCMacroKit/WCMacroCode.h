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

#endif /* WCMacroCode_h */
