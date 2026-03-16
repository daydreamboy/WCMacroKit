//
//  WCMacroDelegate.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroDelegate_h
#define WCMacroDelegate_h

#pragma mark - Delegate performSelector

/// @warning 1. Only apply for delegate methods without return value 2. Only support two arguments at most

#ifndef DELEGATE_SAFE_PERFORM
#define DELEGATE_SAFE_PERFORM(delegate, sel)        \
    do {                                            \
        if ([delegate respondsToSelector:sel]) {    \
            [delegate performSelector:sel];         \
        }                                           \
    } while (0)
#endif /* DELEGATE_SAFE_PERFORM */

#ifndef DELEGATE_SAFE_PERFORM1
#define DELEGATE_SAFE_PERFORM1(delegate, sel, arg1)         \
    do {                                                    \
        if ([delegate respondsToSelector:sel]) {            \
            [delegate performSelector:sel withObject:arg1]; \
        }                                                   \
    } while (0)
#endif /* DELEGATE_SAFE_PERFORM1 */

#ifndef DELEGATE_SAFE_PERFORM2
#define DELEGATE_SAFE_PERFORM2(delegate, sel, arg1, arg2)                   \
    do {                                                                    \
        if ([delegate respondsToSelector:sel]) {                            \
            [delegate performSelector:sel withObject:arg1 withObject:arg2]; \
        }                                                                   \
    } while (0)
#endif /* DELEGATE_SAFE_PERFORM2 */

#pragma mark - Dummy Protocol

#define WCDummyProtocol(name) \
@protocol WCDummyProtocol_##name <NSObject> \
@end

#endif /* WCMacroDelegate_h */
