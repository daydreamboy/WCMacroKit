//
//  WCMacroBlock.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroBlock_h
#define WCMacroBlock_h

#if __has_include(<WCMacroKit/WCMacroUncategoried.h>)
#import <WCMacroKit/WCMacroUncategoried.h>
#else
#import "WCMacroUncategoried.h"
#endif

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
 
 @discussion This maco is deprecated, because can't debug code in the block if the block code inline the macro.
 Use WCBlockSafeRunMainThread c funtion instead.
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
} while (0);

/**
 *  Invoke block more safely, and can used in .mm file
 */
#define BLOCK_SAFE_CALL(block, ...) \
do { \
    if (block) { \
        block(__VA_ARGS__); \
    } \
} while (0);


#pragma mark - Weak-Strong Dance

/**
 Weakify the object variable

 @param object the original variable
 @discussion Use weakify/strongify as pair
 @see https://www.jianshu.com/p/9e18f28bf28d
 @see https://github.com/ReactiveCocoa/ReactiveObjC/blob/master/ReactiveObjC/extobjc/EXTScope.h#L83
 @code
 
 id foo = [[NSObject alloc] init];
 id bar = [[NSObject alloc] init];
 
 weakify(foo);
 weakify(bar);
 
 // this block will not keep 'foo' or 'bar' alive
 BOOL (^matchesFooOrBar)(id) = ^ BOOL (id obj){
    // but now, upon entry, 'foo' and 'bar' will stay alive until the block has
    // finished executing
    strongify(foo);
    strongifyWithReturn(bar, return NO);
 
    return [foo isEqual:obj] || [bar isEqual:obj];
 };
 
 @endcode
 */
#define weakify(object) \
__weak __typeof__(object) object##_weak_ = object;

/**
 Strongify the weak object variable which is created by weakify(object)

 @param object the original variable
 @discussion Use weakify/strongify as pair
 @see https://www.jianshu.com/p/9e18f28bf28d
 @note See #weakify for an example of usage.
 */
#define strongify(object) \
__strong __typeof__(object##_weak_) object = object##_weak_;

/**
 Strongify the weak object variable which is created by weakify(object).
 And optional add a return clause

 @param object the original variable
 @param ... the return clause
 @discussion strongifyWithReturn works as strongify, except for allowing a return clause
 @note See #weakify for an example of usage.
 */
#define strongifyWithReturn(object, ...) \
__strong __typeof__(object##_weak_) object = object##_weak_; \
if (!object) { \
    __VA_ARGS__; \
}

#pragma mark - Delay Release

/**
 Delay release object after the time
 
 @param object_ the object to delayed release
 @param seconds_ the after time to release
 @param queue_ the queue for releasing. If nil, use dispatch_get_main_queue()
 
 @note suggest to use this macro only in dealloc method or the other methods called by dealloc
 
 @see https://blog.ibireme.com/2015/11/12/smooth_user_interfaces_for_ios/
 */
#define DELAY_RELEASE_AFTER(object_, seconds_, queue_) \
typeof(object_) tempObject__ = object_; \
object_ = nil; \
dispatch_queue_t release_queue__ = (queue_) == nil ? dispatch_get_main_queue() : (queue_); \
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(seconds_ * NSEC_PER_SEC)), release_queue__, ^{ \
    [tempObject__ class]; \
});

#pragma mark - Block Scope

typedef void (^wc_cleanupBlock_t)(void);

static inline void wc_executeCleanupBlock (__strong wc_cleanupBlock_t *block) {
    (*block)();
}

/**
 Call block when out of the scope
 
 @discussion This macro same as @onExit
 @example
 SCOPE_ON_EXIT{
     NSLog(@"on exit 1");
 };
 */
#define SCOPE_ON_EXIT \
__strong wc_cleanupBlock_t VARIABLE_CONCAT(wc_SCOPE_ON_EXIT_Block_, __LINE__) __attribute__((cleanup(wc_executeCleanupBlock), unused)) = ^

#endif /* WCMacroBlock_h */
