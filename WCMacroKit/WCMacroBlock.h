//
//  WCMacroBlock.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroBlock_h
#define WCMacroBlock_h

// Block caller
#pragma mark Block caller

/**
 Safe call block

 @param block the block to call
 @param ... the parameters of the block
 @see http://stackoverflow.com/questions/4145164/why-do-nil-null-blocks-cause-bus-errors-when-run
 @note This marco only is suitable for .m, not for .mm file
 */
#define BLOCK_SAFE_RUN(block, ...) block ? block(__VA_ARGS__) : nil

/**
 Safe call block and always on main thread

 @param block the block to call
 @param ... the parameters of the block
 */
#define BLOCK_SAFE_RUN_ON_MAIN_THREAD(block, ...) \
do { \
    if (block) { \
        if ([NSThread isMainThread]) { \
            block(__VA_ARGS__); \
        } \
        else { \
            dispatch_async(dispatch_get_main_queue(), ^{ \
                block(__VA_ARGS__); \
            }); \
        } \
    } \
} while (0)

/**
 *  Invoke block more safely, and can used in .mm file
 */
#define BLOCK_SAFE_CALL(block, ...) \
do { \
    if (block) { \
        block(__VA_ARGS__); \
    } \
} while (0)

#endif /* WCMacroBlock_h */
