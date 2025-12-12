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

#pragma mark - Class method caller

#pragma mark > No return value

/**
 Call class method
 
 @param `classString_` the class string
 @param `selString_` the selector string
 */
#ifndef CLASS_SAFE_CALL
#define CLASS_SAFE_CALL(classString_, selString_) \
    do { \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* CLASS_SAFE_CALL1 */

#pragma mark > With return object type

#ifndef CLASS_SAFE_CALL_WITH_RETURN
#define CLASS_SAFE_CALL_WITH_RETURN(classString_, selString_) \
    ({ \
        id returnValue = nil; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* CLASS_SAFE_CALL_WITH_RETURN */

#ifndef CLASS_SAFE_CALL1_WITH_RETURN
#define CLASS_SAFE_CALL1_WITH_RETURN(classString_, selString_, arg1_) \
    ({ \
        id returnValue = nil; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* CLASS_SAFE_CALL1_WITH_RETURN */

#ifndef CLASS_SAFE_CALL2_WITH_RETURN
#define CLASS_SAFE_CALL2_WITH_RETURN(classString_, selString_, arg1_, arg2_) \
    ({ \
        id returnValue = nil; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* CLASS_SAFE_CALL2_WITH_RETURN */

#ifndef CLASS_SAFE_CALL3_WITH_RETURN
#define CLASS_SAFE_CALL3_WITH_RETURN(classString_, selString_, arg1_, arg2_, arg3_) \
    ({ \
        id returnValue = nil; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* CLASS_SAFE_CALL3_WITH_RETURN */

#pragma mark > With return primitive type

#ifndef CLASS_SAFE_CALL_WITH_RETURN_PRIMITIVE
#define CLASS_SAFE_CALL_WITH_RETURN_PRIMITIVE(classString_, selString_, ret_type_, default_ret_val_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            ret_type tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [(NSObject *)clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* CLASS_SAFE_CALL_WITH_RETURN_PRIMITIVE */

#ifndef CLASS_SAFE_CALL1_WITH_RETURN_PRIMITIVE
#define CLASS_SAFE_CALL1_WITH_RETURN_PRIMITIVE(classString_, selString_, ret_type_, default_ret_val_, arg1_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        Class target = NSClassFromString(classString_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [clz methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* CLASS_SAFE_CALL1_WITH_RETURN_PRIMITIVE */


#pragma mark - Instance method caller

#pragma mark > No return value

#ifndef INSTANCE_SAFE_CALL
#define INSTANCE_SAFE_CALL(instance_, selString_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL */

// Note: float type must append `f`, e.g 4.0 should be 4.0f
/**
 Call instance method with one parameter
 
 @param `instance_` the instance
 @param `selString_` the selector string
 @param `arg1_` the id parameter
 */
#ifndef INSTANCE_SAFE_CALL1
#define INSTANCE_SAFE_CALL1(instance_, selString_, arg1_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL1 */

#ifndef INSTANCE_SAFE_CALL2
#define INSTANCE_SAFE_CALL2(instance_, selString_, arg1_, arg2_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL2 */

#ifndef INSTANCE_SAFE_CALL3
#define INSTANCE_SAFE_CALL3(instance_, selString_, arg1_, arg2_, arg3_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL3 */

#ifndef INSTANCE_SAFE_CALL4
#define INSTANCE_SAFE_CALL4(instance_, selString_, arg1_, arg2_, arg3_, arg4_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL4 */

#ifndef INSTANCE_SAFE_CALL5
#define INSTANCE_SAFE_CALL5(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation setArgument:(void *)&param3 atIndex:4]; \
            [invocation setArgument:(void *)&param4 atIndex:5]; \
            [invocation setArgument:(void *)&param5 atIndex:6]; \
            [invocation invoke]; \
        } \
    } while (0)
#endif /* INSTANCE_SAFE_CALL5 */

#ifndef INSTANCE_SAFE_CALL6
#define INSTANCE_SAFE_CALL6(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            typeof(arg6_) param6 = arg6_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL6 */

#ifndef INSTANCE_SAFE_CALL7
#define INSTANCE_SAFE_CALL7(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_) \
    do { \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            typeof(arg6_) param6 = arg6_; \
            typeof(arg7_) param7 = arg7_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL7 */

#pragma mark > With return object type

#ifndef INSTANCE_SAFE_CALL1_WITH_RETURN
#define INSTANCE_SAFE_CALL1_WITH_RETURN(instance_, selString_, arg1_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* INSTANCE_SAFE_CALL1_WITH_RETURN */

#ifndef INSTANCE_SAFE_CALL2_WITH_RETURN
#define INSTANCE_SAFE_CALL2_WITH_RETURN(instance_, selString_, arg1_, arg2_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = (__bridge id)tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* INSTANCE_SAFE_CALL2_WITH_RETURN */

// @see https://stackoverflow.com/questions/22018272/nsinvocation-returns-value-but-makes-app-crash-with-exc-bad-access
#ifndef INSTANCE_SAFE_CALL3_WITH_RETURN
#define INSTANCE_SAFE_CALL3_WITH_RETURN(instance_, selString_, arg1_, arg2_, arg3_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL3_WITH_RETURN */

#ifndef INSTANCE_SAFE_CALL4_WITH_RETURN
#define INSTANCE_SAFE_CALL4_WITH_RETURN(instance_, selString_, arg1_, arg2_, arg3_, arg4_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL4_WITH_RETURN */

#ifndef INSTANCE_SAFE_CALL5_WITH_RETURN
#define INSTANCE_SAFE_CALL5_WITH_RETURN(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL5_WITH_RETURN */

#ifndef INSTANCE_SAFE_CALL6_WITH_RETURN
#define INSTANCE_SAFE_CALL6_WITH_RETURN(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            typeof(arg6_) param6 = arg6_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL6_WITH_RETURN */

#ifndef INSTANCE_SAFE_CALL7_WITH_RETURN
#define INSTANCE_SAFE_CALL7_WITH_RETURN(instance_, selString_, arg1_, arg2_, arg3_, arg4_, arg5_, arg6_, arg7_) \
    ({ \
        NSObject *target = (NSObject *)(instance_); \
        id returnValue = nil; \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            typeof(arg5_) param5 = arg5_; \
            typeof(arg6_) param6 = arg6_; \
            typeof(arg7_) param7 = arg7_; \
            void *tempReturnValue = nil; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL7_WITH_RETURN */

#pragma mark > With return primitive type

#ifndef INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE
#define INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE(instance_, selString_, ret_type_, default_ret_val_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* INSTANCE_SAFE_CALL_WITH_RETURN_PRIMITIVE */

#ifndef INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE
#define INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE(instance_, selString_, ret_type_, default_ret_val_, arg1_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* INSTANCE_SAFE_CALL1_WITH_RETURN_PRIMITIVE */

#ifndef INSTANCE_SAFE_CALL2_WITH_RETURN_PRIMITIVE
#define INSTANCE_SAFE_CALL2_WITH_RETURN_PRIMITIVE(instance_, selString_, ret_type_, default_ret_val_, arg1_, arg2_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
            invocation.selector = sel; \
            [invocation setArgument:(void *)&param1 atIndex:2]; \
            [invocation setArgument:(void *)&param2 atIndex:3]; \
            [invocation invoke]; \
            [invocation getReturnValue:&tempReturnValue]; \
            returnValue = tempReturnValue; \
        } \
        returnValue; \
    })
#endif /* INSTANCE_SAFE_CALL2_WITH_RETURN_PRIMITIVE */

#ifndef INSTANCE_SAFE_CALL3_WITH_RETURN_PRIMITIVE
#define INSTANCE_SAFE_CALL3_WITH_RETURN_PRIMITIVE(instance_, selString_, ret_type_, default_ret_val_, arg1_, arg2_, arg3_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL3_WITH_RETURN_PRIMITIVE */

#ifndef INSTANCE_SAFE_CALL4_WITH_RETURN_PRIMITIVE
#define INSTANCE_SAFE_CALL4_WITH_RETURN_PRIMITIVE(instance_, selString_, ret_type_, default_ret_val_, arg1_, arg2_, arg3_, arg4_) \
    ({ \
        ret_type_ returnValue = default_ret_val_; \
        NSObject *target = (NSObject *)(instance_); \
        SEL sel = NSSelectorFromString(selString_); \
        if ([target respondsToSelector:sel]) { \
            typeof(arg1_) param1 = arg1_; \
            typeof(arg2_) param2 = arg2_; \
            typeof(arg3_) param3 = arg3_; \
            typeof(arg4_) param4 = arg4_; \
            ret_type_ tempReturnValue = default_ret_val_; \
            NSMethodSignature *methodSignature = [target methodSignatureForSelector:sel]; \
            NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature]; \
            invocation.target = target; \
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
#endif /* INSTANCE_SAFE_CALL4_WITH_RETURN_PRIMITIVE */

#pragma mark - Dummy Protocol

#define WCDummyProtocol(name) \
@protocol WCDummyProtocol_##name <NSObject> \
@end

#endif /* WCMacroDelegate_h */
