//
//  WCCallerTool.m
//  AppTest
//
//  Created by wesley_chen on 20/12/2017.
//

#import "WCCallerTool.h"

@implementation WCCallerTool

+ (id)callAndReturn:(id)sender selector:(SEL)selector {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call1AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call2AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call3AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call4AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call5AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call6AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        typeof(param6) arg6 = param6;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation setArgument:&arg6 atIndex:7];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (id)call7AndReturn:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7 {
    id returnValue = nil;
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        typeof(param6) arg6 = param6;
        typeof(param7) arg7 = param7;
        void *tempReturnValue = nil;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation setArgument:&arg6 atIndex:7];
        [invocation setArgument:&arg7 atIndex:8];
        [invocation invoke];
        [invocation getReturnValue:&tempReturnValue];
        returnValue = (__bridge id)tempReturnValue;
    }
    return returnValue;
}

+ (void)call:(id)sender selector:(SEL)selector {
    if ([sender respondsToSelector:selector]) {
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation invoke];
    }
}

+ (void)call1:(id)sender selector:(SEL)selector param1:(id)param1 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation invoke];
    }
}

+ (void)call2:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation invoke];
    }
}

+ (void)call3:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation invoke];
    }
}

+ (void)call4:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation invoke];
    }
}

+ (void)call5:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation invoke];
    }
}

+ (void)call6:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        typeof(param6) arg6 = param6;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation setArgument:&arg6 atIndex:7];
        [invocation invoke];
    }
}

+ (void)call7:(id)sender selector:(SEL)selector param1:(id)param1 param2:(id)param2 param3:(id)param3 param4:(id)param4 param5:(id)param5 param6:(id)param6 param7:(id)param7 {
    if ([sender respondsToSelector:selector]) {
        typeof(param1) arg1 = param1;
        typeof(param2) arg2 = param2;
        typeof(param3) arg3 = param3;
        typeof(param4) arg4 = param4;
        typeof(param5) arg5 = param5;
        typeof(param6) arg6 = param6;
        typeof(param7) arg7 = param7;
        NSMethodSignature *methodSignature = [sender methodSignatureForSelector:selector];
        NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        invocation.target = sender;
        invocation.selector = selector;
        [invocation setArgument:&arg1 atIndex:2];
        [invocation setArgument:&arg2 atIndex:3];
        [invocation setArgument:&arg3 atIndex:4];
        [invocation setArgument:&arg4 atIndex:5];
        [invocation setArgument:&arg5 atIndex:6];
        [invocation setArgument:&arg6 atIndex:7];
        [invocation setArgument:&arg7 atIndex:8];
        [invocation invoke];
    }
}

@end
