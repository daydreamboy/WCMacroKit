//
//  WCMacroAssert.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//  Credited to https://github.com/insanehunter/NSAssert-BackingActions
//

#ifndef WCMacroAssert_h
#define WCMacroAssert_h

#import <Foundation/NSException.h>

/// Use NS_ASSERT_SUPRESS_BACKING_ACTION_LOGGING to disable console log
#if !defined(NSReleaseAssertionLog)
    #if !defined(NS_ASSERT_SUPRESS_BACKING_ACTION_LOGGING)
        #define NSReleaseAssertionLog(desc, ...)    NSLog(desc, ##__VA_ARGS__)
    #else
        #define NSReleaseAssertionLog(desc, ...)
    #endif // !defined(NS_ASSERT_SUPRESS_BACKING_ACTION_LOGGING)
#endif // !defined(NSReleaseAssertionLog)

#define NSAssertWithReleaseAction(releaseAction, condition, desc, ...)                  \
    {                                                                                   \
        @try { \
            if (!(condition)) {                                                             \
                NSReleaseAssertionLog(@"*** Assertion failure in %@, %s:%d. Reason: %@",    \
                    NSStringFromSelector(_cmd), __FILE__, __LINE__,                         \
                    [NSString stringWithFormat:desc, ##__VA_ARGS__]);                       \
                [NSException raise:@"Assert Exception" format:@""];                         \
            }                                                                               \
        }                                                                                   \
        @catch (NSException *exception) {                                                   \
            NSLog(@"exception on call stack: %@", exception.callStackSymbols);              \
            releaseAction;                                                                  \
        }                                                  \
    }

#define NSAssertOrReturn(condition, desc, ...) \
                NSAssertWithReleaseAction(return, condition, desc, ##__VA_ARGS__)
#define NSAssertOrReturnNil(condition, desc, ...) \
                NSAssertWithReleaseAction(return nil, condition, desc, ##__VA_ARGS__)
#define NSAssertOrReturnNO(condition, desc, ...) \
                NSAssertWithReleaseAction(return NO, condition, desc, ##__VA_ARGS__)
#define NSAssertOrBreak(condition, desc, ...) \
                NSAssertWithReleaseAction(break, condition, desc, ##__VA_ARGS__)
#define NSAssertOrContinue(condition, desc, ...) \
                NSAssertWithReleaseAction(continue, condition, desc, ##__VA_ARGS__)
#define NSAssertOrDoNothing(condition, desc, ...) \
                NSAssertWithReleaseAction(nil, condition, desc, ##__VA_ARGS__)

#define NSParameterAssertOrReturn(condition) \
                NSAssertWithReleaseAction(return, condition, @"Invalid parameter not satisfying: %s", #condition)
#define NSParameterAssertOrReturnNil(condition) \
                NSAssertWithReleaseAction(return nil, condition, @"Invalid parameter not satisfying: %s", #condition)
#define NSParameterAssertOrReturnNO(condition) \
                NSAssertWithReleaseAction(return NO, condition, @"Invalid parameter not satisfying: %s", #condition)
#define NSParameterAssertOrBreak(condition) \
                NSAssertWithReleaseAction(break, condition, @"Invalid parameter not satisfying: %s", #condition)
#define NSParameterAssertOrContinue(condition) \
                NSAssertWithReleaseAction(continue, condition, @"Invalid parameter not satisfying: %s", #condition)

#endif /* WCMacroAssert_h */
