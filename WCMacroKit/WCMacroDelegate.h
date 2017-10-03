//
//  WCMacroDelegate.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroDelegate_h
#define WCMacroDelegate_h

// Delegate caller
#pragma mark Delegate caller

/// @warning
// 1. Only apply for delegate methods with return value
// 2. Only support two arguments at most
// 3. parameter only support object

#ifndef DELEGATE_SAFE_CALL_WITH_RETURN
#define DELEGATE_SAFE_CALL_WITH_RETURN(delegate, selector)   \
    ({                                                       \
        id returnVal;                                        \
        if ([delegate respondsToSelector:selector]) {        \
            returnVal = [delegate performSelector:selector]; \
        }                                                    \
        returnVal;                                           \
    })
#endif /* DELEGATE_SAFE_CALL_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL1_WITH_RETURN
#define DELEGATE_SAFE_CALL1_WITH_RETURN(delegate, selector, arg1)            \
    ({                                                                       \
        id returnVal;                                                        \
        if ([delegate respondsToSelector:selector]) {                        \
            returnVal = [delegate performSelector:selector withObject:arg1]; \
        }                                                                    \
        returnVal;                                                           \
    })
#endif /* DELEGATE_SAFE_CALL1_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL2_WITH_RETURN
#define DELEGATE_SAFE_CALL2_WITH_RETURN(delegate, selector, arg1, arg2)                      \
    ({                                                                                       \
        id returnVal;                                                                        \
        if ([delegate respondsToSelector:selector]) {                                        \
            returnVal = [delegate performSelector:selector withObject:arg1 withObject:arg2]; \
        }                                                                                    \
        returnVal;                                                                           \
    })
#endif /* DELEGATE_SAFE_CALL2_WITH_RETURN */

/// @warning 1. Only apply for delegate methods without return value 2. Only support two arguments at most

#ifndef DELEGATE_SAFE_CALL
#define DELEGATE_SAFE_CALL(delegate, selector)        \
    do {                                              \
        if ([delegate respondsToSelector:selector]) { \
            [delegate performSelector:selector];      \
        }                                             \
    } while (0)
#endif /* DELEGATE_SAFE_CALL */

#ifndef DELEGATE_SAFE_CALL1
#define DELEGATE_SAFE_CALL1(delegate, selector, arg1)            \
    do {                                                         \
        if ([delegate respondsToSelector:selector]) {            \
            [delegate performSelector:selector withObject:arg1]; \
        }                                                        \
    } while (0)
#endif /* DELEGATE_SAFE_CALL1 */

#ifndef DELEGATE_SAFE_CALL2
#define DELEGATE_SAFE_CALL2(delegate, selector, arg1, arg2)                      \
    do {                                                                         \
        if ([delegate respondsToSelector:selector]) {                            \
            [delegate performSelector:selector withObject:arg1 withObject:arg2]; \
        }                                                                        \
    } while (0)
#endif /* DELEGATE_SAFE_CALL2 */

#pragma mark - Dummy Protocol

#define WCDummyProtocol(name) \
@protocol WCDummyProtocol_##name <NSObject> \
@end

#endif /* WCMacroDelegate_h */
