//
//  WCMacroDelegate.h
//  WCMacroKit
//
//  Created by wesley chen on 16/8/28.
//
//

#ifndef WCMacroDelegate_h
#define WCMacroDelegate_h

/// Delegate caller
// Note: float type must append `f`, e.g 4.0 should be 4.0f
#pragma mark Delegate caller

#pragma mark > With return object type

#ifndef DELEGATE_SAFE_CALL_WITH_RETURN
#define DELEGATE_SAFE_CALL_WITH_RETURN(delegate, sel) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL1_WITH_RETURN
#define DELEGATE_SAFE_CALL1_WITH_RETURN(delegate, sel, arg1) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL1_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL2_WITH_RETURN
#define DELEGATE_SAFE_CALL2_WITH_RETURN(delegate, sel, arg1, arg2) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL2_WITH_RETURN */

// @see https://stackoverflow.com/questions/22018272/nsinvocation-returns-value-but-makes-app-crash-with-exc-bad-access
#ifndef DELEGATE_SAFE_CALL3_WITH_RETURN
#define DELEGATE_SAFE_CALL3_WITH_RETURN(delegate, sel, arg1, arg2, arg3) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL3_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL4_WITH_RETURN
#define DELEGATE_SAFE_CALL4_WITH_RETURN(delegate, sel, arg1, arg2, arg3, arg4) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL4_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL5_WITH_RETURN
#define DELEGATE_SAFE_CALL5_WITH_RETURN(delegate, sel, arg1, arg2, arg3, arg4, arg5) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL5_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL6_WITH_RETURN
#define DELEGATE_SAFE_CALL6_WITH_RETURN(delegate, sel, arg1, arg2, arg3, arg4, arg5, arg6) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            typeof(arg6) param6 = arg6; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation setArgument:(void *)&param6 atIndex:7]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL6_WITH_RETURN */

#ifndef DELEGATE_SAFE_CALL7_WITH_RETURN
#define DELEGATE_SAFE_CALL7_WITH_RETURN(delegate, sel, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    ({ \
        id returnValue = nil; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            typeof(arg6) param6 = arg6; \
            typeof(arg7) param7 = arg7; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation setArgument:(void *)&param6 atIndex:7]; \
            [invocation setArgument:(void *)&param7 atIndex:8]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL7_WITH_RETURN */

#pragma mark > With return primitive type

#ifndef DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE
#define DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE(delegate, sel, ret_type, default_ret_val) \
    ({ \
        ret_type returnValue = default_ret_val; \
        if ([delegate respondsToSelector:sel]) { \
            ret_type tempReturnValue = default_ret_val; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL_WITH_RETURN_PRIMITIVE */

#ifndef DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE
#define DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(delegate, sel, ret_type, default_ret_val, arg1) \
    ({ \
        ret_type returnValue = default_ret_val; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            ret_type tempReturnValue = default_ret_val; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL1_WITH_RETURN_PRIMITIVE */

#ifndef DELEGATE_SAFE_CALL2_WITH_RETURN_PRIMITIVE
#define DELEGATE_SAFE_CALL2_WITH_RETURN_PRIMITIVE(delegate, sel, ret_type, default_ret_val, arg1, arg2) \
    ({ \
        ret_type returnValue = default_ret_val; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            ret_type tempReturnValue = default_ret_val; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL2_WITH_RETURN_PRIMITIVE */

#ifndef DELEGATE_SAFE_CALL3_WITH_RETURN_PRIMITIVE
#define DELEGATE_SAFE_CALL3_WITH_RETURN_PRIMITIVE(delegate, sel, ret_type, default_ret_val, arg1, arg2, arg3) \
    ({ \
        ret_type returnValue = default_ret_val; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            ret_type tempReturnValue = default_ret_val; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL3_WITH_RETURN_PRIMITIVE */

#ifndef DELEGATE_SAFE_CALL4_WITH_RETURN_PRIMITIVE
#define DELEGATE_SAFE_CALL4_WITH_RETURN_PRIMITIVE(delegate, sel, ret_type, default_ret_val, arg1, arg2, arg3, arg4) \
    ({ \
        ret_type returnValue = default_ret_val; \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            ret_type tempReturnValue = default_ret_val; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* DELEGATE_SAFE_CALL4_WITH_RETURN_PRIMITIVE */

#pragma mark > No return value

#ifndef DELEGATE_SAFE_CALL
#define DELEGATE_SAFE_CALL(delegate, sel) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL */

#ifndef DELEGATE_SAFE_CALL1
#define DELEGATE_SAFE_CALL1(delegate, sel, arg1) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL1 */

#ifndef DELEGATE_SAFE_CALL2
#define DELEGATE_SAFE_CALL2(delegate, sel, arg1, arg2) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL2 */

#ifndef DELEGATE_SAFE_CALL3
#define DELEGATE_SAFE_CALL3(delegate, sel, arg1, arg2, arg3) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL3 */

#ifndef DELEGATE_SAFE_CALL4
#define DELEGATE_SAFE_CALL4(delegate, sel, arg1, arg2, arg3, arg4) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL4 */

#ifndef DELEGATE_SAFE_CALL5
#define DELEGATE_SAFE_CALL5(delegate, sel, arg1, arg2, arg3, arg4, arg5) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL5 */

#ifndef DELEGATE_SAFE_CALL6
#define DELEGATE_SAFE_CALL6(delegate, sel, arg1, arg2, arg3, arg4, arg5, arg6) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            typeof(arg6) param6 = arg6; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation setArgument:(void *)&param6 atIndex:7]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL6 */

#ifndef DELEGATE_SAFE_CALL7
#define DELEGATE_SAFE_CALL7(delegate, sel, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    do { \
        if ([delegate respondsToSelector:sel]) { \
            typeof(arg1) param1 = arg1; \
            typeof(arg2) param2 = arg2; \
            typeof(arg3) param3 = arg3; \
            typeof(arg4) param4 = arg4; \
            typeof(arg5) param5 = arg5; \
            typeof(arg6) param6 = arg6; \
            typeof(arg7) param7 = arg7; \
            NSMethodSignature *methodSignature = [(NSObject *)delegate methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = delegate; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation setArgument:(void *)&param6 atIndex:7]; \
            [invocation setArgument:(void *)&param7 atIndex:8]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* DELEGATE_SAFE_CALL7 */

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

#pragma mark - Class method caller

/**
 Call class method
 
 @param `classString_` the class string
 @param `selString_` the selector string
 */
#ifndef CLASS_SAFE_CALL
#define CLASS_SAFE_CALL(classString_, selString_) \
    do { \
        Class clz = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([clz respondsToSelector:sel]) { \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = clz; \
            invocation.selector = sel; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* CLASS_SAFE_CALL */

/**
 Call class method with one parameter
 
 @param `classString_` the class string
 @param `selString_` the selector string
 @param `arg1_` the id parameter
 */
#ifndef CLASS_SAFE_CALL1
#define CLASS_SAFE_CALL1(classString_, selString_, arg1_) \
    do { \
        Class clz = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([clz respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = clz; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* CLASS_SAFE_CALL1 */

#pragma mark - Instance method caller

#ifndef INSTANCE_SAFE_CALL
#define INSTANCE_SAFE_CALL(instance_, selString_) \
    do { \
        SEL sel = NSSelectorFromString(selString_); \
        if ([instance_ respondsToSelector:sel]) { \
            NSMethodSignature *methodSignature = [(NSObject *)instance_ methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = instance_; \
            invocation.selector = sel; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL */

/**
 Call instance method with one parameter
 
 @param `instance_` the instance
 @param `selString_` the selector string
 @param `arg1_` the id parameter
 */
#ifndef INSTANCE_SAFE_CALL1
#define INSTANCE_SAFE_CALL1(instance_, selString_, arg1_) \
    do { \
        SEL sel = NSSelectorFromString(selString_); \
        if ([instance_ respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            NSMethodSignature *methodSignature = [(NSObject *)instance_ methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = instance_; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL1 */

#pragma mark - Dummy Protocol

#define WCDummyProtocol(name) \
@protocol WCDummyProtocol_##name <NSObject> \
@end

#endif /* WCMacroDelegate_h */
