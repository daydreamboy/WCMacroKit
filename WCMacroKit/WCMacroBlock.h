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

// @sa http://stackoverflow.com/questions/4145164/why-do-nil-null-blocks-cause-bus-errors-when-run
#define BLOCK_SAFE_RUN(block, ...)    block ? block(__VA_ARGS__) : nil

/**
 *  Invoke block more safely, and can used in .mm file
 */
#define BLOCK_SAFE_CALL(block, ...) \
    do {                            \
        if (block) {                \
            block(__VA_ARGS__);     \
        }                           \
    } while (0)

#endif /* WCMacroBlock_h */
